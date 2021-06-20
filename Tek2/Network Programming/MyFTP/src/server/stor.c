/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** stor
*/

#include "server/my_ftp.h"

void stor_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
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
    if (count_arg_command(command) < 2) {
        send_response(fd, 501, "Not enough argument.");
    } else {
        stor_func_two(client, command[1]);
    }
}

int create_file(int fd, char *filepath)
{
    int fd_file = open(filepath, O_WRONLY | O_CREAT, 0744);
    if (fd_file < 0) {
        return -1;
    }
    FILE *fPtr = fopen(filepath, "a");
    char buff[2] = {0};
    while (1) {
        int nbBytes = read(fd, buff, 1);
        if (nbBytes < 0)
            return -1;
        else if (nbBytes == 0)
            break;
        fputs(buff, fPtr);
    }
    fclose(fPtr);
    return 1;
}

void stor_func_two(client_ftp_t *client, char *arg)
{
    struct sockaddr_in sa;
    socklen_t size = sizeof(sa);
    int tmp_client = accept(client->socket_mode, (struct sockaddr *)&sa, &size);
    if (tmp_client < 0)
        send_response(client->socket, 425, "Error connection");
    else
        send_response(client->socket, 150, "Data connexion opened");
    int st = create_file(tmp_client, arg);
    if (st >= 0)
        send_response(client->socket, 226, "Upload completed.");
    else
        send_response(client->socket, 500, "Internal error. \
        Check permission / if file exists.");
    close(client->socket_mode);
    close(tmp_client);
    client->state = NONE;
}
