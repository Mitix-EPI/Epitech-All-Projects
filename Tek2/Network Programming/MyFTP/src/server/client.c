/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** client
*/

#include "server/my_ftp.h"

client_ftp_t *init_new_client(void)
{
    client_ftp_t *client = malloc(sizeof(*client));

    client->socket = 0;
    client->isLogged = 0;
    client->port = 0;
    client->ip = NULL;
    client->username = NULL;
    client->password = NULL;
    client->anonym = 0;
    client->isQuit = 0;
    return client;
}

void quit_client(serv_ftp_t *serv, client_ftp_t *client)
{
    close(client->socket);
    FD_CLR(client->socket, &serv->activeFdSet);
    client->socket = 0;
    client->isQuit = 0;
}
