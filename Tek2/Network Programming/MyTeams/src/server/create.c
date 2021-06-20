/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** create
*/

#include "server/myteams.h"

int create_error_handling(client_t *cli)
{
    char buf[4096] = {0};

    switch (cli->_context) {
        case UNKNOWN_TEAM:
            snprintf(buf, sizeof(buf), "%s\r\n", "create error unknown_team");
            write(cli->_socket, buf, strlen(buf));
            return (1);
        case UNKNOWN_CHANNEL:
            snprintf(buf, sizeof(buf), "%s\r\n", \
            "create error unknown_channel");
            write(cli->_socket, buf, strlen(buf));
            return (1);
        case UNKNOWN_THREAD:
            snprintf(buf, sizeof(buf), "%s\r\n", \
            "create error unknown_thread");
            write(cli->_socket, buf, strlen(buf));
            return (1);
        default:
            return (0);
    }
}

void create_management(server_t *s, client_t *cli, char **command)
{
    if (!create_error_handling(cli)) {
        create_team(s, cli, command);
        create_channel(s, cli, command);
        create_thread(s, cli, command);
        create_reply(s, cli, command);
    }
}

void create_func(server_t *s, client_t *cli, char **command)
{
    if (len_command(command) > 3 || len_command(command) == 1)
        printf("Internal error CREATE\n");
    else
        create_management(s, cli, command);
}