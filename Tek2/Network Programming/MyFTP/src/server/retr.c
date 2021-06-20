/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** retr
*/

#include "server/my_ftp.h"

void retr_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
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
        retr_func_two(client, command[1]);
    }
}

void retr_func_two(client_ftp_t *client, char *arg)
{
    struct sockaddr_in sa;
    socklen_t size = sizeof(sa);
    int tmp_client = accept(client->socket_mode, (struct sockaddr *)&sa, &size);
    if (tmp_client < 0)
        send_response(client->socket, 425, "Error connection");
    else
        send_response(client->socket, 150, "Data connexion opened");

    int st = send_path(tmp_client, arg);
    if (st >= 0)
        send_response(client->socket, 226, "Download completed.");
    else
        send_response(client->socket, 500, "Internal error. \
        Check permission / if file exists.");
    close(client->socket_mode);
    close(tmp_client);
    client->state = NONE;
}

int send_file(int fd, FILE *f)
{
    size_t size = 1024;
    char filebuf[size +1];
    int n = 0;
    int ret = 0;
    while ((n = fread(filebuf, 1, size, f)) > 0) {
        int st = write(fd, filebuf, n);
        if (st < 0) {
            ret = -1;
            break;
        } else {
            filebuf[n] = 0;
        }
    }
    return ret;
}

int send_path(int fd, char *file)
{
    FILE *f = fopen(file, "rb");
    if (f) {
        fseek(f, 0, SEEK_SET);
        int st = send_file(fd, f);
        if (st < 0) {
            return -2;
        }
    } else {
        return -1;
    }
    int ret = fclose(f);
    return ret == 0 ? 0 : -3;
}
