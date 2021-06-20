/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** myteams
*/

#ifndef MYTEAMS_H_
#define MYTEAMS_H_

#define EXIT_ERROR 84
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>

#include <uuid/uuid.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include "logging_client.h"

#include "../common/get_next_line.h"

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

typedef struct user_data_s
{
    char uuid[37];
    char username[MAX_NAME_LENGTH];
    int sts;
} user_data_t;

typedef struct users_list_s {
    user_data_t usr;
    struct users_list_s *next;
} users_list_t;

typedef struct team_data_s
{
    char uuid[37];
    char name[MAX_NAME_LENGTH];
    char descr[MAX_DESCRIPTION_LENGTH];
} team_data_t;

typedef struct teams_list_s {
    team_data_t team;
    struct teams_list_s *next;
} teams_list_t;

typedef struct subteam_list_s {
    char _team_uuid[37];
    struct subteam_list_s *next;
} subteam_list_t;

typedef struct client_s {
    struct sockaddr_in serv_addr;
    int sock;
    char *buffer;

    fd_set read_fds;
    fd_set write_fds;
    fd_set except_fds;

    char uuid[37];
    char user_name[MAX_NAME_LENGTH];
    int is_logged;
    context_e _context;

    subteam_list_t *subteam;
} client_t;

// main.c
int is_valid_ip_address(char *ipAddress);
int display_help(void);
int display_error(char *message);

// init_client.c
void connection_to_server(client_t *cli);
client_t init_client(char *ip, int port);

// read_client.c
void read_stdin_and_send_buffer(client_t *cli);
void read_from_server(client_t *cli);

// launch_client.c
void reset_fds(client_t *cli);
void handle_select_errors(int sel, client_t cli);
void main_loop(client_t cli);
void launch_client(char *ip, int port);

// handle_command.c
size_t len_command(char **command);
void handle_command(client_t *cli, char *buffer);
void free_command(char **command);
char **parse_command(char *buffer);

// handle_response.c
void handle_response(client_t *cli, char *buffer);

// help.c
void help_func(client_t *cli, char **command);

// login.c
void login_func(client_t *cli, char **command);
void login_res(client_t *cli, char **command);

// logout.c
void logout_func(client_t *cli, char **command);
void logout_res(client_t *cli, char **command);

// users.c
void users_func(client_t *cli, char **command);
void users_res(client_t *cli, char **command);
users_list_t *parse_data(char **command);
void free_users_list(users_list_t *usersList);

// users_2.c
void get_username(char *cmd, char *tmp);
void get_uuid(char *cmd, char *tmp);
int get_status(char *cmd);
void get_description(char *cmd, char *tmp);

// user.c
void user_func(client_t *cli, char **command);
void user_res(client_t *cli, char **command);

// send.c
void send_func(client_t *cli, char **command);
void send_res(client_t *cli, char **command);

// messages.c
void messages_func(client_t *cli, char **command);
void messages_res(client_t *cli, char **command);

// use.c
void use_func(client_t *cli, char **command);
void use_res(client_t *cli, char **command);

// create.c
void create_func(client_t *cli, char **command);
void create_res(client_t *cli, char **command);
void create_team(char **command);
void create_channel(char **command);
void create_thread(char **command);
void create_reply(char **command);

// usefull.c
int check_quote(char *str);
char *remove_quote(char *str);

// chained_list_users.c
users_list_t *add_user_at_the_end(user_data_t usr, users_list_t *strct);
teams_list_t *add_teamslist_at_the_end(team_data_t team, teams_list_t *strct);
void reversed_display(users_list_t *head);
int exist_node(char *name, users_list_t *head);
subteam_list_t *add_subteam_at_the_end(char *team_uuid, subteam_list_t *strct);

// subscribe.c
void subscribe_func(client_t *cli, char **command);
void subscribe_res(client_t *cli, char **command);

// subscribed.c
void subscribed_func(client_t *cli, char **command);
void subscribed_res(client_t *cli, char **command);

// subscribed2.c
void subscribed_all_users_sub_team(client_t *cli, char **command);
void subscribed_all_teams_subed(client_t *cli, char **command);

// subscribed3.c
users_list_t *parse_users_data(char **command);
void remove_quotes_sub(char *src);

#endif /* !MYTEAMS_H_ */
