/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_server3
*/

#include "server/myteams.h"

void fill_addr_serv_struct(server_t *s)
{
    s->_addr.sin_family = AF_INET;
    s->_addr.sin_addr.s_addr = INADDR_ANY;
    s->_addr.sin_port = htons(s->_port);
    s->_max_fd = s->_sfd;
}

void init_server(int port, server_t *s)
{
    s->_sfd = socket(AF_INET, SOCK_STREAM, 0);
    s->_port = port;
    s->_opt = 1;
    s->_max_client = 42;
    if (s->_sfd < 0)
        display_error("[X]Error: init_server (line 16): set sfd");
    if (setsockopt(s->_sfd, SOL_SOCKET, SO_REUSEADDR, &s->_opt, \
sizeof(int)) != 0)
        display_error("[X]Error: init_server (line 18): set sockopt");
    memset(&s->_addr, 0, sizeof(s->_addr));
    fill_addr_serv_struct(s);
    if (bind(s->_sfd, (struct sockaddr*)&s->_addr, \
sizeof(struct sockaddr)) != 0)
        display_error("[X]Error: init_server (line 24): bind");
    if (listen(s->_sfd, 10) != 0)
        display_error("[X]Error: init_server (line 26): listen");
    init_client(s);
    printf("Server: Accepting connections on port %d...\n", s->_port);
}

int buff_ends(char *buff)
{
    for (size_t i = 0; buff && buff[i]; i++)
        if (buff[i] == '\r' && i + 1 < strlen(buff) && buff[i + 1] == '\n')
            return (1);
    return (0);
}

void render_command(char cmd[4096 + 1], char *buffer)
{
    memset(cmd, 0, 4096 + 1);
    for (size_t i = 0; buffer && buffer[i]; i++)
        cmd[i] = buffer[i];
}

void disconnect_client(client_t *cli, server_t *s)
{
    if (cli->_logged_in == 1)
        server_event_user_logged_out(cli->_uuid);
    printf("[-]Disconnection client from %s:%d\n", \
inet_ntoa(cli->_addr.sin_addr), ntohs(cli->_addr.sin_port));
    close(cli->_socket);
    FD_CLR(cli->_socket, &s->_read_fds);
    cli->_socket = NO_SOCKET;
}
