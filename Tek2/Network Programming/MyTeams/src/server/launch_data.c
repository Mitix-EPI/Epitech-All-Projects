/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_data
*/

#include "server/myteams.h"

void launch_replies(server_t *s)
{
    list_replies_t *tmp_reply = s->_replies;
    list_threads_t *tmp_thread = s->_threads;

    while (tmp_reply) {
        while (tmp_thread) {
            if (strcmp(tmp_thread->_thread._uuid, \
            tmp_reply->_reply._thread_uuid) == 0)
                tmp_thread->_thread._reply_list = \
                add_reply_at_the_end(tmp_reply->_reply, \
                tmp_thread->_thread._reply_list);
            tmp_thread = tmp_thread->next;
        }
        tmp_reply = tmp_reply->next;
    }
}

void launch_threads(server_t *s)
{
    list_channels_t *tmp_channel = s->_channels;
    list_threads_t *tmp_thread = s->_threads;

    while (tmp_thread) {
        while (tmp_channel) {
            if (strcmp(tmp_channel->_channel._uuid, \
            tmp_thread->_thread._channel_uuid) == 0)
                tmp_channel->_channel._threads = \
                add_thread_at_the_end(tmp_thread->_thread, \
                tmp_channel->_channel._threads);
            tmp_channel = tmp_channel->next;
        }
        tmp_thread = tmp_thread->next;
    }
}

void launch_channels(server_t *s)
{
    list_teams_t *tmp_team = s->_teams;
    list_channels_t *tmp_channel = s->_channels;

    while (tmp_channel) {
        while (tmp_team) {
            if (strcmp(tmp_team->_team._uuid, \
            tmp_channel->_channel._team_uuid) == 0)
                tmp_team->_team._channels = \
                add_channel_at_the_end(tmp_channel->_channel, \
                tmp_team->_team._channels);
            tmp_team = tmp_team->next;
        }
        tmp_channel = tmp_channel->next;
    }
}