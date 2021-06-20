/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** init_client
*/

#include "client/myteams.h"

void connection_to_server(client_t *cli)
{
    if ((cli->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        display_error("Socket creation error.");
        exit(EXIT_ERROR);
    }
    if (connect(cli->sock, (struct sockaddr *)&cli->serv_addr, \
    sizeof(cli->serv_addr)) < 0) {
        display_error("Connection failed.");
        exit(EXIT_ERROR);
    }
}

client_t init_client(char *ip, int port)
{
    client_t cli;

    cli.is_logged = 0;
    cli._context = ROOT;
    memset(cli.user_name, 0, MAX_NAME_LENGTH);
    cli.serv_addr.sin_family = AF_INET;
    cli.serv_addr.sin_addr.s_addr = inet_addr(ip);
    cli.serv_addr.sin_port = htons(port);
    connection_to_server(&cli);
    cli.subteam = NULL;
    printf("Connected to %s:%d\n", ip, port);
    return (cli);
}