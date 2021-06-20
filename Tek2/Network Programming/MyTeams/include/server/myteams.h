/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** myteams
*/

#ifndef MYTEAMS_H_
#define MYTEAMS_H_

#define EXIT_ERROR 84

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>

#include <netinet/in.h>
#include <netdb.h>

#include <arpa/inet.h>

#include <uuid/uuid.h>

#include "logging_server.h"

#define NO_SOCKET -1
#define EXIT_ERROR 84
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef enum context_e
{
    ROOT,
    TEAM,
    CHANNEL,
    THREAD,
    UNKNOWN_TEAM,
    UNKNOWN_CHANNEL,
    UNKNOWN_THREAD,
}context_e;

typedef struct command_s
{
    char *command;
    void(*ptr)();
} command_t;

typedef struct user_team_s
{
    char _cli_uuid[37];
    char _team_uuid[37];
} user_team_t;

typedef struct list_subteam_s {
    user_team_t _usr_team_linked;
    struct list_subteam_s *next;
} list_subteam_t;

typedef struct client_s {
    int _socket;
    struct sockaddr_in _addr;
    socklen_t _len;
    char _ip[INET_ADDRSTRLEN];
    char _cmd[4096 + 1];
    char _prev_cmd[4096 + 1];
    char _uuid[37];
    char _username[MAX_NAME_LENGTH];
    int _logged_in;
    context_e _context;
} __attribute__((packed)) client_t;

typedef struct user_s {
    char _username[MAX_NAME_LENGTH];
    char _uuid[37];
} __attribute__((packed)) user_t;

typedef struct reply_s {
    char _user_uuid[37];
    char _body[MAX_BODY_LENGTH];
    char _thread_uuid[37];
} __attribute__((packed)) reply_t;

typedef struct list_replies_s {
    reply_t _reply;
    struct list_replies_s *next;
} list_replies_t;

typedef struct thread_s {
    char _title[MAX_NAME_LENGTH];
    char _uuid[37];
    char _body[MAX_BODY_LENGTH];
    char _user_uuid[37];
    char _channel_uuid[37];
    list_replies_t *_reply_list;
} __attribute__((packed)) thread_t;

typedef struct list_threads_s {
    thread_t _thread;
    struct list_threads_s *next;
} list_threads_t;

typedef struct channel_s {
    char _channel_name[MAX_NAME_LENGTH];
    char _desc[MAX_DESCRIPTION_LENGTH];
    char _uuid[37];
    char _team_uuid[37];
    list_threads_t *_threads;
} __attribute__((packed)) channel_t;

typedef struct list_channels_s {
    channel_t _channel;
    struct list_channels_s *next;
} list_channels_t;

typedef struct team_s {
    char _team_name[MAX_NAME_LENGTH];
    char _desc[MAX_DESCRIPTION_LENGTH];
    char _uuid[37];
    char _user_uuid[37];
    char *_members[37];
    list_channels_t *_channels;
} __attribute__((packed)) team_t;

typedef struct list_teams_s {
    team_t _team;
    struct list_teams_s *next;
} list_teams_t;

typedef struct message_s {
    char _receiver_uuid[37];
    char _sender_uuid[37];
    char _body[MAX_BODY_LENGTH];
    time_t _time;
} __attribute__((packed)) message_t;

typedef struct list_users_s {
    user_t usr;
    struct list_users_s *next;
} list_users_t;

typedef struct list_messages_s {
    message_t msg;
    struct list_messages_s *next;
} list_messages_t;

typedef struct server_s {
    int _sfd;
    int _opt;
    int _port;
    int _max_client;
    int _flag;
    int _max_fd;
    char _actual_context_uuid[37];
    struct sockaddr_in _addr;
    client_t _c_list[42];
    list_subteam_t *_subteam;
    list_users_t *_users;
    list_messages_t *_msgs;
    list_teams_t *_teams;
    list_channels_t *_channels;
    list_threads_t *_threads;
    list_replies_t *_replies;
    char *_buffer;
    fd_set _read_fds;
    fd_set _write_fds;
    fd_set _except_fds;
} server_t;

// main.c
int display_help(void);
int display_error(char *message);

// launch_server.c
void launch_server(int port);

// launch_server2.c
void update_fds(server_t *s);
void clean_shutdown(server_t *server, char *message);
void handle_new_connection(server_t *server);
void init_client(server_t *server);

// launch_server3.c
void fill_addr_serv_struct(server_t *s);
void init_server(int port, server_t *s);
int buff_ends(char *buff);
void render_command(char cmd[4096 + 1], char *buffer);
void disconnect_client(client_t *cli, server_t *s);

// launch_server4.c
void display_reading_from_client(server_t *s, int i);
void *my_malloc(size_t size);
int read_from_client(server_t *s, int i);
void handle_activity(server_t *s);
void check_activity(server_t *server);

// launch_server5.c
void handle_activity_2(server_t *s, int i);

// handle_command.c
void handle_command(server_t *s, client_t *cli, char *buffer);
size_t len_command(char **command);
char **parse_command(char *buffer);
void free_command(char **command);

// login.c
void login_func(server_t *s, client_t *cli, char **command);

// logout.c
void logout_func(server_t *s, client_t *cli, char **command);

// db_client.c
void save_clients(server_t *s);
void read_clients(server_t *s);

// db_messages.c
void save_messages(server_t *s);
void read_messages(server_t *s);

// db_teams.c
void save_teams(server_t *s);
void read_teams(server_t *s);

// db_reply.c
void save_reply(server_t *s);
void read_reply(server_t *s);

// db_thread.c
void save_thread(server_t *s);
void read_thread(server_t *s);

// db_channels.c
void read_channels(server_t *s);
void save_channels(server_t *s);

// db_subscribe.c
void save_sub_clients_teams(server_t *s);
void read_sub_clients_teams(server_t *s);

// chained_list.c
list_users_t *add_node_at_the_end(user_t usr, list_users_t *strct);
list_teams_t *add_team_at_the_end(team_t team, list_teams_t *strct);
list_channels_t *add_channel_at_the_end(channel_t chnl, \
list_channels_t *strct);
void reversed_display(list_users_t *head);
int exist_node(char *name, list_users_t *head);

// chained_list2.c
list_replies_t *add_reply_at_the_end(reply_t repl, list_replies_t *strct);
list_threads_t *add_thread_at_the_end(thread_t thrd, list_threads_t *strct);
list_subteam_t *add_subteam_at_the_end(user_team_t usr_team_linkd, \
list_subteam_t *strct);

// users.c
void users_func(server_t *s, client_t *cli, char **command);
void format_user_data(char *uuid, char *username, int status, char *data);
int user_is_connected(server_t *s, char *username);
int user_is_connected_uuid(server_t *s, char *uuid);

// send.c
void send_func(server_t *s, client_t *cli, char **command);
int is_user_exists(server_t *s, char *uuid);

// messages.c
void messages_func(server_t *s, client_t *cli, char **command);

// user.c
void user_func(server_t *s, client_t *cli, char **command);

// use.c
void use_func(server_t *s, client_t *cli, char **command);

// usefull.c
char *remove_quote(char *str);
void generate_new_uuid(char *uuid);

// create.c
void create_func(server_t *s, client_t *cli, char **command);
void create_team(server_t *s, client_t *cli, char **command);
void create_channel(server_t *s, client_t *cli, char **command);
void create_thread(server_t *s, client_t *cli, char **command);
void create_reply(server_t *s, client_t *cli, char **command);

// create_send_to_client.c
void create_team_send_to_client(server_t *s, client_t *cli, team_t tmp_team);
void create_channel_send_to_client(server_t *s, client_t *cli, \
channel_t tmp_channel);
void create_thread_send_to_client(server_t *s, client_t *cli, \
thread_t tmp_thread);
void create_reply_send_to_client(server_t *s, client_t *cli, \
reply_t tmp_reply);

// command_sender.c
void send_to_all_connected_users(server_t *s, client_t *cli, char *to_send);
void send_event_channel_to_team(server_t *s, client_t *cli, char *to_send, \
channel_t channel);
void send_event_reply_to_team(server_t *s, client_t *cli, char *to_send);

// messages_list.c
list_messages_t *add_messages_at_the_end(message_t usr, \
list_messages_t *strct);

// check_create.c
int is_team_exist(server_t *s, char *team_name);
int is_team_exist_uuid(server_t *s, char *team_name);
int is_channel_exist(server_t *s, char *channel_name);
int is_thread_exist(server_t *s, char *thread_title);

// validity.c
int is_valid_team(server_t *s, char *team_uuid);
int is_valid_channel(server_t *s, char *channel_uuid);
int is_valid_thread(server_t *s, char *thread_uuid);

// subscribe.c
void subscribe_func(server_t *s, client_t *cli, char **command);

// subscribed.c
void subscribed_func(server_t *s, client_t *cli, char **command);

// get_from_list.c
team_t get_team_from_uuid(server_t *s, char *uuid);
char *get_team_uuid_from_reply(server_t *s, char *thread_uuid);

#endif /* !MYTEAMS_H_ */
