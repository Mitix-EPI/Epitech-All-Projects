/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_client
*/

#include "client/myteams.h"

void reset_fds(client_t *cli)
{
    FD_ZERO(&cli->read_fds);
    FD_SET(STDIN_FILENO, &cli->read_fds);
    FD_SET(cli->sock, &cli->read_fds);

    FD_ZERO(&cli->write_fds);

    FD_ZERO(&cli->except_fds);
    FD_SET(STDIN_FILENO, &cli->except_fds);
    FD_SET(cli->sock, &cli->except_fds);
}

void handle_select_errors(int sel, client_t cli)
{
    if (sel <= 0) {
        display_error("Select error occures.");
        exit(EXIT_ERROR);
    }
    if (FD_ISSET(STDIN_FILENO, &cli.except_fds)) {
        display_error("STDIN except.");
        exit(EXIT_ERROR);
    }
    if (FD_ISSET(cli.sock, &cli.except_fds)) {
        display_error("Server except.");
        exit(EXIT_ERROR);
    }
}

int buff_ends_client(char *buff)
{
    for (size_t i = 0; buff && buff[i]; i++)
        if (buff[i] == '\n')
            return (1);
    return (0);
}

void main_loop(client_t cli)
{
    int maxFd = cli.sock;

    while (1) {
        reset_fds(&cli);
        int sel = select(maxFd + 1, &cli.read_fds, &cli.write_fds, \
        &cli.except_fds, NULL);
        handle_select_errors(sel, cli);
        if (FD_ISSET(STDIN_FILENO, &cli.read_fds))
            read_stdin_and_send_buffer(&cli);
        if (FD_ISSET(cli.sock, &cli.read_fds))
            read_from_server(&cli);
    }
}

void launch_client(char *ip, int port)
{
    client_t cli = init_client(ip, port);
    printf("Client running\n");
    main_loop(cli);
}
