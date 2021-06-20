/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** run
*/

#include "server/my_ftp.h"

void init_run(serv_ftp_t *serv, client_ftp_t *clients[100])
{
    FD_ZERO(&serv->activeFdSet);
    FD_SET(serv->servers[0].serverfd, &serv->activeFdSet);
    for (int i = 0; i < MAX_CLIENTS; i++)
        clients[i] = init_new_client();
    for (int i = 1; i < MAX_CLIENTS; i++)
        serv->servers[i] = init_empty_server();
    serv->max_sd = 0;
}

void reset_fds(serv_ftp_t *serv, client_ftp_t *clients[100])
{
    FD_ZERO(&serv->readFdSet);
    for (int i = 0; i < MAX_SERVERS; i++) {
        if (serv->servers[i].serverfd != 0) {
            FD_SET(serv->servers[i].serverfd, &serv->readFdSet);
            if (serv->servers[i].serverfd > serv->max_sd)
                serv->max_sd = serv->servers[i].serverfd;
        }
    }
    for (int i = 0, sd = 0; i < MAX_CLIENTS; i++) {
        sd = clients[i]->socket;
        if (sd > 0)
            FD_SET(sd, &serv->readFdSet);
        if (sd > serv->max_sd)
            serv->max_sd = sd;
    }
}

void accept_new_connection(serv_ftp_t *serv, client_ftp_t *clients[100], int i)
{
    int newConnection = 0;
    struct sockaddr_in client;
    socklen_t addrlen = sizeof(client);
    if ((newConnection = accept(serv->servers[i].serverfd,
    (struct sockaddr *)&client, &addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_ERROR);
    }
    FD_SET(newConnection, &serv->activeFdSet);
    send_response(newConnection, 220, "Connection Established");
    printf("[+] Connection client from %s:%d\n",
    inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    for (int j = 0; j < MAX_CLIENTS; j++) {
        if (clients[j]->socket == 0) {
            clients[j]->socket = newConnection;
            clients[j]->address = client;
            clients[j]->state = serv->servers[i].state;
            break;
        }
    }
}

void check_incoming_request(serv_ftp_t *serv, client_ftp_t *clients[100])
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if ((FD_ISSET(clients[i]->socket, &serv->readFdSet))) {
            int next = handle_incoming_request(serv, clients, i);
            if (next)
                continue;
        }
    }
}

int handle_incoming_request(serv_ftp_t *serv, client_ftp_t *clients[100], int i)
{
    char buff[2] = {0};
    serv->buffer = malloc(sizeof(char) * (4096 + 1));
    memset(serv->buffer, 0, 4096);
    while (1) {
        int nbBytes = read(clients[i]->socket, buff, 1);
        if (nbBytes < 0) {
            perror("Error reading incoming stream");
            exit(EXIT_ERROR);
        } else if (nbBytes == 0) {
            printf("[-] Disconnection client from %s:%d\n", \
inet_ntoa(clients[i]->address.sin_addr), ntohs(clients[i]->address.sin_port));
            close(clients[i]->socket);
            FD_CLR(clients[i]->socket, &serv->activeFdSet);
            break;
        }
        serv->buffer = my_strcat(serv->buffer, buff);
        if (buff_ends(serv->buffer))
            break;
    }
    exec_request(serv, clients, i);
    return 0;
}
