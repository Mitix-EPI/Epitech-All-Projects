/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** validity
*/

#include "server/myteams.h"

int is_valid_team(server_t *s, char *team_uuid)
{
    list_teams_t *tmp_teams = s->_teams;

    while (tmp_teams) {
        if (strcmp(tmp_teams->_team._uuid, team_uuid) == 0)
            return (1);
        tmp_teams = tmp_teams->next;
    }
    return (0);
}

int is_valid_channel(server_t *s, char *channel_uuid)
{
    list_channels_t *tmp_channels = s->_channels;

    while (tmp_channels) {
        if (strcmp(tmp_channels->_channel._uuid, channel_uuid) == 0)
            return (1);
        tmp_channels = tmp_channels->next;
    }
    return (0);
}

int is_valid_thread(server_t *s, char *thread_uuid)
{
    list_threads_t *tmp_threads = s->_threads;

    while (tmp_threads) {
        if (strcmp(tmp_threads->_thread._uuid, thread_uuid) == 0)
            return (1);
        tmp_threads = tmp_threads->next;
    }
    return (0);
}
