/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_server2
*/

#include "server/myteams.h"

void init_client(server_t *server)
{
    for (int i = 0; i < server->_max_client; i++) {
        server->_c_list[i]._socket = NO_SOCKET;
        memset(server->_c_list[i]._cmd, 0, 4096 + 1);
        memset(server->_c_list[i]._prev_cmd, 0, 4096 + 1);
        server->_c_list[i]._logged_in = 0;
    }
    server->_users = NULL;
    server->_msgs = NULL;
    server->_replies = NULL;
    server->_teams = NULL;
    server->_threads = NULL;
    server->_channels = NULL;
    server->_subteam = NULL;
    read_clients(server);
    read_messages(server);
    read_reply(server);
    read_teams(server);
    read_thread(server);
    read_channels(server);
    read_sub_clients_teams(server);
}

void update_fds(server_t *s)
{
    FD_ZERO(&s->_read_fds);
    FD_SET(s->_sfd, &s->_read_fds);
    for (int i = 0; i < s->_max_client; i++) {
        if (s->_c_list[i]._socket != NO_SOCKET)
            FD_SET(s->_c_list[i]._socket, &s->_read_fds);
        if (s->_c_list[i]._socket > s->_max_fd)
            s->_max_fd = s->_c_list[i]._socket;
    }
    FD_ZERO(&s->_write_fds);
    for (int i = 0; i < s->_max_client; ++i)
        if (s->_c_list[i]._socket != NO_SOCKET)
            FD_SET(s->_c_list[i]._socket, &s->_write_fds);
    FD_ZERO(&s->_except_fds);
    FD_SET(s->_sfd, &s->_except_fds);
    for (int i = 0; i < s->_max_client; ++i)
        if (s->_c_list[i]._socket != NO_SOCKET)
            FD_SET(s->_c_list[i]._socket, &s->_except_fds);
}

void clean_shutdown(server_t *server, char *message)
{
    for (int i = 0; i < server->_max_client; i++)
        if (server->_c_list[i]._socket != NO_SOCKET)
            close(server->_c_list[i]._socket);
    close(server->_sfd);
    display_error(message);
    save_clients(server);
    save_channels(server);
    save_messages(server);
    save_reply(server);
    save_teams(server);
    save_thread(server);
    save_sub_clients_teams(server);
    exit(0);
}

void handle_new_connection(server_t *server)
{
    for (int i = 0; i < server->_max_client; i++) {
        if (server->_c_list[i]._socket == NO_SOCKET) {
            server->_c_list[i]._len = sizeof(server->_c_list[i]._addr);
            memset(&server->_c_list[i]._addr, 0, server->_c_list[i]._len);
            if ((server->_c_list[i]._socket = accept(server->_sfd,
            (struct sockaddr *)&server->_c_list[i]._addr,
            &server->_c_list[i]._len)) < 0)
                display_error("[X]Error: accept new client");
            inet_ntop(AF_INET, &server->_c_list[i]._addr.sin_addr,
            server->_c_list[i]._ip, INET_ADDRSTRLEN);
            printf("[+]Server: Incoming connection from %s:%d.\n",
            server->_c_list[i]._ip, server->_c_list[i]._addr.sin_port);
            return;
        }
    }
}
