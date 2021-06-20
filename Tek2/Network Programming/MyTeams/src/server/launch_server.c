/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_server
*/

#include "server/myteams.h"

void run_server(server_t *server)
{
    printf("Waiting for incoming connections...\n");
    while (1) {
        update_fds(server);
        check_activity(server);
    }
}

server_t *get_serv_struct(void)
{
    static server_t res;

    return (&res);
}

static void sig_handler(int code)
{
    (void) code;
    server_t *res = get_serv_struct();

    for (int i = 0; i < res->_max_client; i++)
        if (res->_c_list[i]._socket != NO_SOCKET) {
            close(res->_c_list[i]._socket);
            res->_c_list[i]._socket = NO_SOCKET;
        }
    save_clients(res);
    save_channels(res);
    save_messages(res);
    save_reply(res);
    save_teams(res);
    save_thread(res);
    save_sub_clients_teams(res);
    printf("\nSaving data\n");
    exit(EXIT_SUCCESS);
}

void launch_server(int port)
{
    server_t *server = get_serv_struct();

    signal(SIGINT, sig_handler);
    signal(SIGPIPE, sig_handler);
    init_server(port, server);
    run_server(server);
}
