/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** commands2
*/

#include "server/my_ftp.h"

void dele_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    if (count_arg_command(command) < 2) {
        send_response(fd, 501, "Not enough argument.");
        return;
    }
    if (delete_file(command[1]))
        send_response(fd, 250, "File deleted.");
    else
        send_response(fd, 550, "File does not exist.");
}

void pwd_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    char path[100] = {0};
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    if (!getcwd(path, 100)) {
        send_response(fd, 550, "Failed to get CWD.");
        return;
    }
    char *tmp = strdup(path);
    char buffer[1024] = {0};
    sprintf(buffer, "%s is current directory.", tmp);
    char *res = strdup(buffer);
    send_response(fd, 257, res);
    free(tmp);
    free(res);
}

void noop_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    send_response(fd, 200, "Command okay.");
}

void help_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    int fd = client->socket;
    send_response(fd, 214, "Commands: USER PASS CWD CDUP QUIT DELE PWD PASV \
PORT NOOP RETR STOR LIST");
}

void null_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) serv;
    (void) command;
    int fd = client->socket;
    send_response(fd, 84, "Command not already handled.");
}
