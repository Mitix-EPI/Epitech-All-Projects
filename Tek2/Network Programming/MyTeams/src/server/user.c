/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** user
*/

#include "server/myteams.h"

void find_user(server_t *s, char **command, char *buf)
{
    list_users_t *tmp = s->_users;
    int usr_exist = 1;

    command[1]++;
    command[1][strlen(command[1]) - 1] = 0;
    while (tmp) {
        if (strcmp(tmp->usr._uuid, command[1]) == 0) {
            int status = user_is_connected(s, tmp->usr._username);
            char data[76] = {0};
            snprintf(data, 74, " %s %s %d ", tmp->usr._uuid, \
            tmp->usr._username, status);
            strcat(buf, data);
            usr_exist = 0;
            break;
        }
        tmp = tmp->next;
    }
    if (usr_exist == 1)
        snprintf(buf, 4096, " %s %s ", command[1], "error");
}

void user_func(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};

    if (len_command(command) != 2) {
        printf("Internal error USER\n");
        snprintf(buf, sizeof(buf), "%s %s %s\r\n", "user", \
        command[1], "error");
    } else {
        snprintf(buf, sizeof(buf), "%s", "user");
        find_user(s, command, buf);
        strcat(buf, "\r\n");
    }
    write(cli->_socket, buf, strlen(buf));
}
