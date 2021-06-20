/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** check_create
*/

#include "server/myteams.h"

int is_team_exist_uuid(server_t *s, char *team_uuid)
{
    list_teams_t *tmp_teams = s->_teams;

    while (tmp_teams) {
        if (strcmp(tmp_teams->_team._uuid, team_uuid) == 0)
            return (1);
        tmp_teams = tmp_teams->next;
    }
    return (0);
}

int is_team_exist(server_t *s, char *team_name)
{
    list_teams_t *tmp_teams = s->_teams;

    while (tmp_teams) {
        if (strcmp(tmp_teams->_team._team_name, team_name) == 0)
            return (1);
        tmp_teams = tmp_teams->next;
    }
    return (0);
}

int is_channel_exist(server_t *s, char *channel_name)
{
    list_channels_t *tmp_channels = s->_channels;

    while (tmp_channels) {
        if (strcmp(tmp_channels->_channel._channel_name, channel_name) == 0)
            return (1);
        tmp_channels = tmp_channels->next;
    }
    return (0);
}

int is_thread_exist(server_t *s, char *thread_title)
{
    list_threads_t *tmp_threads = s->_threads;

    while (tmp_threads) {
        if (strcmp(tmp_threads->_thread._title, thread_title) == 0)
            return (1);
        tmp_threads = tmp_threads->next;
    }
    return (0);
}