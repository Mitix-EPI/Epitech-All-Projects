/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** list
*/

#include "server/my_ftp.h"

int send_list(int fd, char *cmd)
{
    FILE *fp = popen(cmd, "r");
    char buff[500] = {0};

    if (!fp) {
        return 0;
    }
    while (fgets(buff, 500, fp)) {
        dprintf(fd, "%s", buff);
    }
    pclose(fp);
    return 1;
}

void exit_list_client(char *cmd, int fd1, int fd2)
{
    free(cmd);
    close(fd1);
    close(fd2);
}

void list_func_two(client_ftp_t *client, char *arg)
{
    struct sockaddr_in sa;
    socklen_t size = sizeof(sa);
    int tmp_client = accept(client->socket_mode, (struct sockaddr *)&sa, &size);
    if (tmp_client < 0)
        send_response(client->socket, 425, "Error connection");
    else
        send_response(client->socket, 150, "Data connexion opened");
    char default_cmd[] = "ls -l ";
    char *cmd = NULL;
    if (arg)
        cmd = strdup(strcat(default_cmd, arg));
    else
        cmd = strdup(default_cmd);
    if (send_list(tmp_client, cmd))
        send_response(client->socket, 226, "Completed");
    else
        send_response(client->socket, 501, "Internal Error");
    exit_list_client(cmd, client->socket_mode, tmp_client);
    client->state = NONE;
}

void list_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) serv;
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    if (!is_mode_activated(client)) {
        send_response(fd, 425, "Mode required.");
        return;
    }
    int nb = count_arg_command(command);
    if (nb == 1) {
        list_func_two(client, NULL);
    } else if (nb == 2) {
        list_func_two(client, command[1]);
    }
}
