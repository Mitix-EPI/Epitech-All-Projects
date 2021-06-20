/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** login
*/

#include "server/myteams.h"

int user_exists(server_t *s, char *username, char *uuid)
{
    list_users_t *tmp = s->_users;
    while (tmp) {
        if (strcmp(tmp->usr._username, username) == 0) {
            strcpy(uuid, tmp->usr._uuid);
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void create_user(server_t *s, char *username, char *uuid)
{
    user_t usr;
    strncpy(usr._username, username, MAX_NAME_LENGTH);
    strncpy(usr._uuid, uuid, 37);
    s->_users = add_node_at_the_end(usr, s->_users);
}

void login_notification_users(char *buf, server_t *s, client_t *cli)
{
    write(cli->_socket, buf, strlen(buf));
    char buff[1060] = {0};
    for (int i = 0; i < s->_max_client; i++) {
        if (s->_c_list[i]._socket != NO_SOCKET &&
        s->_c_list[i]._socket != cli->_socket &&
        s->_c_list[i]._logged_in == 1) {
            memset(buff, 0, 1060);
            snprintf(buff, sizeof(buff), "%s %s %s\r\n", "login",
            cli->_uuid, cli->_username);
            write(s->_c_list[i]._socket, buff, strlen(buff));
        }
    }
}

void login_func(server_t *s, client_t *cli, char **command)
{
    char buf[1060] = {0};
    char uuid[37] = {0};

    if (len_command(command) != 2) {
        printf("Internal error LOGIN\n");
        snprintf(buf, sizeof(buf), "%s %s\r\n", "login", "error");
    } else {
        uuid_t uuid_tmp;
        if (!user_exists(s, command[1], uuid)) {
            uuid_generate(uuid_tmp);
            uuid_unparse_lower(uuid_tmp, uuid);
            create_user(s, command[1], uuid);
            server_event_user_created(uuid, command[1]);
        }
        server_event_user_logged_in(uuid);
        snprintf(buf, sizeof(buf), "%s %s %s\r\n", "login", "success", uuid);
        strcpy(cli->_uuid, uuid);
        strcpy(cli->_username, command[1]);
        cli->_logged_in = 1;
    }
    login_notification_users(buf, s, cli);
}
