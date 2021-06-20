/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** gets_from_list
*/

#include "server/myteams.h"

team_t get_team_from_uuid(server_t *s, char *uuid)
{
    team_t res;
    res._channels = NULL;
    list_teams_t *tmp = s->_teams;

    while (tmp) {
        if (strcmp(tmp->_team._uuid, uuid) == 0)
            return (tmp->_team);
        tmp = tmp->next;
    }
    return (res);
}

char *get_team_uuid_from_reply_2(server_t *s, list_threads_t *tmpThreads, \
list_teams_t *tmpTeam, char *thread_uuid)
{
    while (tmpThreads) {
        if (strcmp(tmpThreads->_thread._uuid, thread_uuid) == 0)
            return tmpTeam->_team._uuid;
        tmpThreads = tmpThreads->next;
    }
    return NULL;
}

list_channels_t *get_channels_from_team_uuid(server_t *s, char *team_uuid)
{
    list_channels_t *res = NULL;
    list_channels_t *tmp = s->_channels;

    while (tmp) {
        if (strcmp(tmp->_channel._team_uuid, team_uuid) == 0)
            res = add_channel_at_the_end(tmp->_channel, res);
        tmp = tmp->next;
    }
    return res;
}

list_threads_t *get_threads_from_team_uuid(server_t *s, char *channel_uuid)
{
    list_threads_t *res = NULL;
    list_threads_t *tmp = s->_threads;

    while (tmp) {
        if (strncmp(tmp->_thread._channel_uuid, channel_uuid, 37) == 0)
            res = add_thread_at_the_end(tmp->_thread, res);
        tmp = tmp->next;
    }
    return res;
}

char *get_team_uuid_from_reply(server_t *s, char *thread_uuid)
{
    list_teams_t *tmpTeam = s->_teams;

    while (tmpTeam) {
        list_channels_t *tmpChannels = get_channels_from_team_uuid(s, \
        tmpTeam->_team._uuid);
        while (tmpChannels) {
            list_threads_t *tmpThreads = get_threads_from_team_uuid(s, \
            tmpChannels->_channel._uuid);
            char *res = get_team_uuid_from_reply_2(s, tmpThreads, tmpTeam, \
            thread_uuid);
            if (res)
                return res;
            tmpChannels = tmpChannels->next;
        }
        tmpTeam = tmpTeam->next;
    }
    return NULL;
}