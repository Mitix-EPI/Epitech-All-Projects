/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** read_client
*/

#include "client/myteams.h"

void read_stdin_and_send_buffer(client_t *cli)
{
    char *buffer = get_next_line(0);
    if (!buffer)
        exit(0);
    handle_command(cli, buffer);

}

void read_from_server(client_t *cli)
{
    char buffer[1024] = {0};

    read(cli->sock, buffer, 1024);
    handle_response(cli, buffer);
}
