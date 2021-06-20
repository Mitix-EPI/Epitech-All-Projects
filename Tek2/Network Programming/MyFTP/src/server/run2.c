/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** run2
*/

#include "server/my_ftp.h"

int buff_ends(char *buff)
{
    for (size_t i = 0; buff && buff[i]; i++)
        if (buff[i] == '\r' && i + 1 < strlen(buff) && buff[i + 1] == '\n')
            return 1;
    return 0;
}

void exec_request(serv_ftp_t *serv, client_ftp_t *clients[100], int i)
{
    show_client(clients[i]);
    printf("CMD: %s\n", serv->buffer);
    handle_command(clients[i], serv->buffer, serv);
    if (clients[i]->isQuit == 1)
        quit_client(serv, clients[i]);
    free(serv->buffer);
}

void check_incoming_servers(serv_ftp_t *serv, client_ftp_t *clients[100])
{
    for (int i = 0; i < MAX_SERVERS; i++)
        if (serv->servers[i].serverfd != 0)
            if (FD_ISSET(serv->servers[i].serverfd, &serv->readFdSet))
                accept_new_connection(serv, clients, i);
}
