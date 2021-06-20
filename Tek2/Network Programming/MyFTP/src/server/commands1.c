/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** commands1
*/

#include "server/my_ftp.h"

void user_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) serv;
    int fd = client->socket;
    if (count_arg_command(command) < 2) {
        send_response(fd, 501, "Not enough argument.");
        return;
    }
    if (strcmp(command[1], "Anonymous") == 0)
        client->anonym = 1;
    else
        client->username = strdup(command[1]);
    send_response(fd, 331, "User name okay, need password.");
}

void pass_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) serv;
    int fd = client->socket;
    if (client->anonym) {
        send_response(fd, 230, "User logged in, proceed.");
        client->isLogged = 1;
        return;
    }
    if (count_arg_command(command) < 2) {
        send_response(fd, 501, "Not enough argument.");
        return;
    }
    if (!client->username) {
        send_response(fd, 530, "User not logged.");
        return;
    }
    send_response(fd, 530, "User not logged.");
}

void quit_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    int fd = client->socket;
    if (client->username)
        free(client->username);
    client->username = NULL;
    if (client->password)
        free(client->password);
    client->password = NULL;
    client->anonym = 0;
    client->isLogged = 0;
    client->isQuit = 1;
    send_response(fd, 221, "Service closing control connection. \
Logged out if appropriate.");
}

void cwd_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
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
    if (change_dir(command[1])) {
        send_response(fd, 250, "Directory changed.");
    } else {
        send_response(fd, 550, "Failed to change directory.");
    }
}

void cdup_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    if (change_dir("../")) {
        send_response(fd, 250, "Directory changed.");
    } else {
        send_response(fd, 550, "Failed to change directory.");
    }
}
