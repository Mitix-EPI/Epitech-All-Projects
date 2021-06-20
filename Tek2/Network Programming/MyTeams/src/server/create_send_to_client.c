/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** create_send_to_client
*/

#include "server/myteams.h"

void create_team_send_to_client(server_t *s, client_t *cli, \
team_t team)
{
    char buf1[4096] = {0};
    char buf2[4096] = {0};

    snprintf(buf2, sizeof(buf2), "%s \"%s\" \"%s\" \"%s\"\r\n", \
    "create team success", team._uuid, team._team_name, team._desc);
    write(cli->_socket, buf2, strlen(buf2));
    snprintf(buf1, sizeof(buf1), "%s \"%s\" \"%s\" \"%s\"\r\n", \
    "create team event", team._uuid, team._team_name, team._desc);
    send_to_all_connected_users(s, cli, buf1);
}

void create_channel_send_to_client(server_t *s, client_t *cli, \
channel_t channel)
{
    char buf1[4096] = {0};
    char buf2[4096] = {0};

    snprintf(buf1, sizeof(buf1), "%s \"%s\" \"%s\" \"%s\"\r\n", \
    "create channel event", channel._uuid, channel._channel_name, \
    channel._desc);
    send_event_channel_to_team(s, cli, buf1, channel);
    snprintf(buf2, sizeof(buf2), "%s \"%s\" \"%s\" \"%s\"\r\n", \
    "create channel success", channel._uuid, channel._channel_name, \
    channel._desc);
    write(cli->_socket, buf2, strlen(buf2));
}

void create_thread_send_to_client(server_t *s, client_t *cli, \
thread_t thread)
{
    (void) s;
    char buf1[4096] = {0};
    char buf2[4096] = {0};

    snprintf(buf1, sizeof(buf1), "%s \"%s\" \"%s\" %ld \"%s\" \"%s\"\r\n", \
    "create thread event", thread._uuid, thread._user_uuid,
    time(NULL), thread._title, thread._body);
    snprintf(buf2, sizeof(buf2), "%s \"%s\" \"%s\" %ld \"%s\" \"%s\"\r\n", \
    "create thread success", thread._uuid, thread._user_uuid,
    time(NULL), thread._title, thread._body);
    write(cli->_socket, buf2, strlen(buf2));
}

void create_reply_send_to_client(server_t *s, client_t *cli, reply_t reply)
{
    (void) s;
    char buf1[4096] = {0};
    char buf2[4096] = {0};

    snprintf(buf1, sizeof(buf1), "%s \"%s\" \"%s\" \"%s\" \"%s\"\r\n", \
    "create reply event", reply._thread_uuid, reply._user_uuid, reply._body, \
    get_team_uuid_from_reply(s, reply._thread_uuid));
    send_event_reply_to_team(s, cli, buf1);
    snprintf(buf2, sizeof(buf2), "%s \"%s\" \"%s\" %ld \"%s\"\r\n", \
    "create reply success", reply._thread_uuid, reply._user_uuid, \
    time(NULL), reply._body);
    write(cli->_socket, buf2, strlen(buf2));
}