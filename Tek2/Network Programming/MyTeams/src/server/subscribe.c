/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** subscribe
*/

#include "server/myteams.h"

int is_user_subscribed(server_t *s, client_t *cli, char *team_uuid)
{
    list_subteam_t *tmp = s->_subteam;

    for (; tmp; tmp = tmp->next) {
        if (strcmp(tmp->_usr_team_linked._cli_uuid, cli->_uuid) == 0 && \
        strcmp(tmp->_usr_team_linked._team_uuid, team_uuid) == 0) {
            return (1);
        }
    }
    return (0);
}

void client_sub_team(server_t *s, client_t *cli, char **command)
{
    char buf[1060] = {0};

    if (!is_team_exist_uuid(s, command[1])) {
        snprintf(buf, sizeof(buf), "%s %s\r\n", "subscribe", "error");
    } else if (!is_user_subscribed(s, cli, command[1])) {
        server_event_user_subscribed(command[1], cli->_uuid);
        user_team_t usr_team;

        strncpy(usr_team._cli_uuid, cli->_uuid, 37);
        strncpy(usr_team._team_uuid, command[1], 37);
        s->_subteam = add_subteam_at_the_end(usr_team, s->_subteam);
        snprintf(buf, sizeof(buf), "%s %s %s\r\n", "subscribe", "success", \
        command[1]);
    } else {
        snprintf(buf, sizeof(buf), "%s %s\r\n", "subscribe", \
        "already_subscribed");
    }
    write(cli->_socket, buf, strlen(buf));
}

void subscribe_func(server_t *s, client_t *cli, char **command)
{
    char buf[1060] = {0};

    if (len_command(command) != 2) {
        printf("Internal error SUBSCRIBE\n");
        snprintf(buf, sizeof(buf), "%s %s\r\n", "subscribe", "error");
        write(cli->_socket, buf, strlen(buf));
    } else {
        client_sub_team(s, cli, command);
    }
}
