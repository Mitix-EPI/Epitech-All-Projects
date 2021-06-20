/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_server5
*/

#include "server/myteams.h"

void handle_activity_2(server_t *s, int i)
{
    if (s->_c_list[i]._socket != NO_SOCKET
    && FD_ISSET(s->_c_list[i]._socket, &s->_read_fds)) {
        if (read_from_client(s, i) > 0) {
            handle_command(s, &s->_c_list[i], s->_c_list[i]._cmd);
        }
        return;
    }
    if (s->_c_list[i]._socket != NO_SOCKET
    && FD_ISSET(s->_c_list[i]._socket, &s->_except_fds)) {
        printf("Exception client fd.\n");
        return;
    }
}
