/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** create_succes
*/

#include "server/myteams.h"

void create_team(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};
    if (cli->_context == ROOT) {
        if (is_team_exist(s, remove_quote(command[1]))) {
            snprintf(buf, sizeof(buf), "%s\r\n", \
            "create error already_exist");
            write(cli->_socket, buf, strlen(buf));
            return;
        }
        team_t tmp_team;
        strcpy(tmp_team._team_name, remove_quote(command[1]));
        strcpy(tmp_team._desc, remove_quote(command[2]));
        generate_new_uuid(tmp_team._uuid);
        strcpy(tmp_team._user_uuid, cli->_uuid);
        server_event_team_created(tmp_team._uuid, tmp_team._team_name,
        tmp_team._user_uuid);
        s->_teams = add_team_at_the_end(tmp_team, s->_teams);
        create_team_send_to_client(s, cli, tmp_team);
    }
}

void create_channel(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};

    if (cli->_context == TEAM) {
        if (is_channel_exist(s, remove_quote(command[1]))) {
            snprintf(buf, sizeof(buf), "%s\r\n", \
            "create error already_exist");
            write(cli->_socket, buf, strlen(buf));
            return;
        }
        channel_t tmp_channel;
        strcpy(tmp_channel._channel_name, remove_quote(command[1]));
        strcpy(tmp_channel._desc, remove_quote(command[2]));
        generate_new_uuid(tmp_channel._uuid);
        strcpy(tmp_channel._team_uuid, s->_actual_context_uuid);
        server_event_channel_created(tmp_channel._team_uuid, \
        tmp_channel._uuid, tmp_channel._channel_name);
        s->_channels = add_channel_at_the_end(tmp_channel, s->_channels);
        create_channel_send_to_client(s, cli, tmp_channel);
    }
}

void create_thread(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};
    if (cli->_context == CHANNEL) {
        if (is_thread_exist(s, remove_quote(command[1]))) {
            snprintf(buf, sizeof(buf), "%s\r\n", \
            "create error already_exist");
            write(cli->_socket, buf, strlen(buf));
            return;
        }
        thread_t tmp_thread;
        strcpy(tmp_thread._title, remove_quote(command[1]));
        strcpy(tmp_thread._body, remove_quote(command[2]));
        generate_new_uuid(tmp_thread._uuid);
        strcpy(tmp_thread._user_uuid, cli->_uuid);
        strcpy(tmp_thread._channel_uuid, s->_actual_context_uuid);
        server_event_thread_created(tmp_thread._channel_uuid, \
        tmp_thread._uuid, tmp_thread._user_uuid, tmp_thread._title, \
        tmp_thread._body);
        s->_threads = add_thread_at_the_end(tmp_thread, s->_threads);
        create_thread_send_to_client(s, cli, tmp_thread);
    }
}

void create_reply(server_t *s, client_t *cli, char **command)
{
    if (cli->_context == THREAD) {
        reply_t tmp_reply;
        strcpy(tmp_reply._body, remove_quote(command[1]));
        strcpy(tmp_reply._user_uuid, cli->_uuid);
        strcpy(tmp_reply._thread_uuid, s->_actual_context_uuid);
        server_event_reply_created(tmp_reply._thread_uuid, \
        tmp_reply._user_uuid, tmp_reply._body);
        s->_replies = add_reply_at_the_end(tmp_reply, s->_replies);
        create_reply_send_to_client(s, cli, tmp_reply);
    }
}
