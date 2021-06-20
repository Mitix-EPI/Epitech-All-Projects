/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** command_sender
*/

#include "server/myteams.h"

void send_to_all_connected_users(server_t *s, client_t *cli, char *to_send)
{
    for (int i = 0; i < s->_max_client; i++)
        if (s->_c_list[i]._socket != NO_SOCKET &&
        s->_c_list[i]._socket != cli->_socket &&
        s->_c_list[i]._logged_in == 1)
            write(s->_c_list[i]._socket, to_send, strlen(to_send));
}

int is_user_in_team(client_t cli, char *team_uuid)
{
    (void) cli;
    (void) team_uuid;
    return (0);
}

void send_event_channel_to_team(server_t *s, client_t *cli, char *to_send, \
channel_t channel)
{
    (void) channel;
    for (int i = 0; i < s->_max_client; i++)
        if (s->_c_list[i]._socket != NO_SOCKET &&
        s->_c_list[i]._socket != cli->_socket &&
        s->_c_list[i]._logged_in == 1)
            write(s->_c_list[i]._socket, to_send, strlen(to_send));
}

void send_event_reply_to_team_2(server_t *s, int i, char *to_send, \
list_subteam_t *tmp)
{
    if (strcmp(tmp->_usr_team_linked._cli_uuid, \
    s->_c_list[i]._uuid) == 0 \
    && strcmp(remove_quote(parse_command(to_send)[6]), \
    tmp->_usr_team_linked._team_uuid) == 0)
        write(s->_c_list[i]._socket, to_send, strlen(to_send));
}

void send_event_reply_to_team(server_t *s, client_t *cli, char *to_send)
{
    list_subteam_t *tmp = s->_subteam;

    while (tmp) {
        for (int i = 0; i < s->_max_client; i++) {
            if (s->_c_list[i]._socket != NO_SOCKET &&
            s->_c_list[i]._socket != cli->_socket &&
            s->_c_list[i]._logged_in == 1) {
                send_event_reply_to_team_2(s, i, to_send, tmp);
            }
        }
        tmp = tmp->next;
    }
}