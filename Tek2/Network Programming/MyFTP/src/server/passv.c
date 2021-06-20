/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** passv
*/

#include "server/my_ftp.h"

int send_passv_response(client_ftp_t *client, serv_t *serv)
{
    char *ip = inet_ntoa(serv->address.sin_addr);

    uint16_t port = get_port(serv->serverfd);

    if (port == 0)
        return 0;
    else
        serv->port = port;
    char *message = get_buffer_ip_port(ip, port);
    send_response(client->socket, 227, message);
    serv->state = PASSV;
    client->state = PASSV;
    free(message);
    client->socket_mode = serv->serverfd;
    free(serv);
    return 1;
}

int init_passv(client_ftp_t *client)
{
    (void) client;
    serv_t *serv = init_server_default();
    if (!serv->serverfd)
        return 0;
    return send_passv_response(client, serv);
}

void passv_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) command;
    (void) serv;
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    if (init_passv(client) != 1) {
        send_response(fd, 550, "Error initializing passive mode.");
    }
}

char *get_buffer_ip_port(char *ip, int port)
{
    char buffer[1024] = {0};
    port = ntohs(htons(port));

    for (int i = 0; ip && ip[i]; i++) {
        if (ip[i] == '.')
            ip[i] = ',';
    }
    char tmp[25] = "Entering Passive Mode (\0";
    char *start = strcat(tmp, ip);
    sprintf(buffer, ",%d,%d)", port / 256, port % 256);
    char *end = strdup(buffer);
    char *res = strcat(start, end);
    free(end);
    return strdup(res);
}
