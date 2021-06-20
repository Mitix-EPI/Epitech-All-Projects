/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** init_serv
*/

#include "server/my_ftp.h"

serv_ftp_t *init_serv_struct(serv_ftp_t *serv, int port, char *path)
{
    if (chdir(path) == -1)
        display_error("Error: Path is incorrect.");

    serv->port = htons(port);
    serv->path = strdup(path);
    serv->running = 1;
    return serv;
}

serv_t *init_server_default_error_return(serv_t *serv, int err, const char *msg)
{
    if (err == 1) {
        perror(msg);
        free(serv);
        return NULL;
    }
    if (err == 2) {
        perror(msg);
        close(serv->serverfd);
        free(serv);
        return NULL;
    }
    return NULL;
}

serv_t *init_server_default(void)
{
    serv_t *serv = malloc(sizeof(serv_t));
    if ((serv->serverfd = socket(PF_INET, SOCK_STREAM, 0)) == 0)
        return init_server_default_error_return(serv, 1, "Socket failed");
    serv->address.sin_family = AF_INET;
    serv->address.sin_port = serv->port;
    serv->address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(serv->serverfd,
    (struct sockaddr *)&serv->address, sizeof(serv->address)) < 0)
        return init_server_default_error_return(serv, 2, "Bind failed");
    if (listen(serv->serverfd, 1) < 0)
        return init_server_default_error_return(serv, 2, "Listen failed");
    return serv;
}

void init_server(serv_ftp_t *serv)
{
    if ((serv->servers[0].serverfd = socket(PF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_ERROR);
    }
    serv->servers[0].address.sin_family = AF_INET;
    serv->servers[0].address.sin_port = serv->port;
    serv->servers[0].address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(serv->servers[0].serverfd,
    (struct sockaddr *)&serv->servers[0].address,
    sizeof(serv->servers[0].address)) < 0) {
        perror("Bind failed");
        close(serv->servers[0].serverfd);
        free_serv(serv);
        exit(EXIT_ERROR);
    }
    if (listen(serv->servers[0].serverfd, 1) < 0) {
        perror("Listen failed");
        close(serv->servers[0].serverfd);
        free_serv(serv);
        exit(EXIT_ERROR);
    }
}

serv_t init_empty_server(void)
{
    serv_t serv;

    serv.serverfd = 0;
    serv.state = NONE;
    return serv;
}
