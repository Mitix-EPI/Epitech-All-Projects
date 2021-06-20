/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** logout
*/

#include "server/myteams.h"

void logout_notification_users(char *buf, server_t *s, client_t *cli)
{
    write(cli->_socket, buf, strlen(buf));
    char buff[1060] = {0};
    for (int i = 0; i < s->_max_client; i++) {
        if (s->_c_list[i]._socket != NO_SOCKET &&
        s->_c_list[i]._socket != cli->_socket &&
        s->_c_list[i]._logged_in == 1) {
            memset(buff, 0, 1060);
            snprintf(buff, sizeof(buff), "%s %s %s\r\n", "logout",
            cli->_uuid, cli->_username);
            write(s->_c_list[i]._socket, buff, strlen(buff));
        }
    }
}

void logout_func(server_t *s, client_t *cli, char **command)
{
    (void) s;
    (void) command;
    char buf[1060] = {0};

    server_event_user_logged_out(cli->_uuid);
    snprintf(buf, sizeof(buf), "%s %s\r\n", "logout", "success");
    cli->_logged_in = 0;
    logout_notification_users(buf, s, cli);
    memset(cli->_username, 0, MAX_NAME_LENGTH);
    memset(cli->_uuid, 0, 37);
}
