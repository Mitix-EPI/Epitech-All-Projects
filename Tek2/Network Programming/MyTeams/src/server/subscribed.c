/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** subscribed
*/

#include "server/myteams.h"

char *get_username_from_uuid(server_t *s, char *uuid)
{
    for (int i = 0; i < s->_max_client; i++)
        if (s->_c_list[i]._socket != NO_SOCKET)
            if (strcmp(uuid, s->_c_list[i]._uuid) == 0)
                return (s->_c_list[i]._username);
    return (NULL);
}

void format_team_data(char *uuid, char *name, char *descr, char *data)
{
    snprintf(data, 334, " <%s,\"%s\",\"%s\"> ", uuid, name, descr);
}

void list_all_users_sub_team(server_t *s, client_t *cli, char *team_uuid)
{
    char buf[4096] = {0};

    list_subteam_t *tmp = s->_subteam;
    snprintf(buf, sizeof(buf), "%s %s", "subscribed", "all_users_sub_team");
    while (tmp) {
        if (strcmp(tmp->_usr_team_linked._team_uuid, team_uuid) == 0) {
            int status = user_is_connected_uuid(s, \
            tmp->_usr_team_linked._cli_uuid);
            char data[76] = {0};
            char *username = get_username_from_uuid(s, \
            tmp->_usr_team_linked._cli_uuid);
            format_user_data(tmp->_usr_team_linked._cli_uuid, username, \
            status, data);
            strcat(buf, data);
        }
        tmp = tmp->next;
    }
    strcat(buf, "\r\n");
    write(cli->_socket, buf, strlen(buf));
}

void list_all_teams_of_cli(server_t *s, client_t *cli)
{
    char buf[4096] = {0};

    list_subteam_t *tmp = s->_subteam;
    snprintf(buf, sizeof(buf), "%s %s", "subscribed", "all_teams_subed");
    while (tmp) {
        if (strcmp(tmp->_usr_team_linked._cli_uuid, cli->_uuid) == 0) {
            team_t team = get_team_from_uuid(s, \
            tmp->_usr_team_linked._team_uuid);
            char data[76] = {0};
            format_team_data(team._uuid, team._team_name, \
            team._desc, data);
            strcat(buf, data);
        }
        tmp = tmp->next;
    }
    strcat(buf, "\r\n");
    write(cli->_socket, buf, strlen(buf));
}

void subscribed_func(server_t *s, client_t *cli, char **command)
{
    char buf[1060] = {0};

    if (len_command(command) == 1) {
        list_all_teams_of_cli(s, cli);
    } else {
        if (!is_team_exist_uuid(s, command[1])) {
            snprintf(buf, sizeof(buf), "%s %s\r\n", "subscribe", "error");
            write(cli->_socket, buf, strlen(buf));
            return;
        }
        list_all_users_sub_team(s, cli, command[1]);
    }
}
