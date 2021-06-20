/*
** EPITECH PROJECT, 2021
** users
** File description:
** users
*/

#include "server/myteams.h"

int user_is_connected(server_t *s, char *username)
{
    for (int i = 0; i < s->_max_client; i++)
        if (s->_c_list[i]._socket != NO_SOCKET)
            if (strcmp(username, s->_c_list[i]._username) == 0)
                return (1);
    return (0);
}

int user_is_connected_uuid(server_t *s, char *uuid)
{
    for (int i = 0; i < s->_max_client; i++)
        if (s->_c_list[i]._socket != NO_SOCKET)
            if (strcmp(uuid, s->_c_list[i]._uuid) == 0)
                return (1);
    return (0);
}

void format_user_data(char *uuid, char *username, int status, char *data)
{
    snprintf(data, 76, " <%s,%s,%d> ", uuid, username, status);
}

void users_func(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};

    if (len_command(command) != 1) {
        printf("Internal error USERS\n");
        snprintf(buf, sizeof(buf), "%s %s\r\n", "users", "error");
    } else {
        list_users_t *tmp = s->_users;
        snprintf(buf, sizeof(buf), "%s", "users");
        while (tmp) {
            int status = user_is_connected(s, tmp->usr._username);
            char data[76] = {0};
            format_user_data(tmp->usr._uuid, tmp->usr._username, \
            status, data);
            strcat(buf, data);
            tmp = tmp->next;
        }
        strcat(buf, "\r\n");
    }
    write(cli->_socket, buf, strlen(buf));
}