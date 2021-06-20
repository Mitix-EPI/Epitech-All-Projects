/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** my_ftp
*/

#ifndef MY_FTP_H_
#define MY_FTP_H_

#define EXIT_ERROR 84
#define MAX_CLIENTS 100
#define MAX_SERVERS 100
#define MAX_CLIENT 4096

#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <netdb.h>

typedef struct command_s
{
    char *command;
    void(*ptr)();
} command_t;

enum type_connection {
    NONE = 0,
    PASSV = 1,
    ACTIVE = 2
};

typedef struct ip_s {
    char *ip;
    uint16_t port;
} ip_t;

typedef struct serv_s {
    int serverfd;
    uint16_t port;
    struct sockaddr_in address;

    enum type_connection state;
} serv_t;

typedef struct serv_ftp_s {
    serv_t servers[100];
    uint16_t port;
    char *path;
    int running;

    int max_sd;
    char *buffer;

    fd_set activeFdSet;
    fd_set readFdSet;
} serv_ftp_t;

typedef struct client_ftp_s {
    struct sockaddr_in address;
    int socket;
    int socket_mode;
    int isLogged;
    char *ip;
    uint16_t port;
    char *username;
    char *password;
    int anonym;
    int isQuit;
    enum type_connection state;
} client_ftp_t;

// Commands

// USER
void user_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// PASS
void pass_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// QUIT
void quit_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// CWD
void cwd_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
int change_dir(char *path);
// CDUP
void cdup_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// DELE
void dele_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
int delete_file(char *filePath);
// PWD
void pwd_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// NOOP
void noop_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// HELP
void help_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// NULL
void null_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
// PASV
int send_passv_response(client_ftp_t *client, serv_t *serv);
int init_passv(client_ftp_t *client);
void passv_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
char *get_buffer_ip_port(char *ip, int port);
// PORT
int init_active_mode(ip_t infos, client_ftp_t *client, serv_ftp_t *serv);
void port_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
ip_t parse_ip(char *arg);
char *change_char_from_str(char *str, char c_origin, char new_c);
// RETR
void retr_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
void retr_func_two(client_ftp_t *client, char *arg);
int send_file(int peer, FILE *f);
int send_path(int peer, char *file);
// LIST
void list_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
void list_func_two(client_ftp_t *client, char *arg);
int send_list(int fd, char *cmd);
void exit_list_client(char *cmd, int fd1, int fd2);
// STOR
void stor_func(client_ftp_t *client, char **command, serv_ftp_t *serv);
void stor_func_two(client_ftp_t *client, char *arg);

// is_functions.c
int is_client_logged_in(client_ftp_t *client);
int is_mode_activated(client_ftp_t *client);
int is_valid_ip_address(char *ipAddress);

// count.c
unsigned int rand_interval(unsigned int min, unsigned int max);
int count_arg_command(char **command);
int count_char(char *str, char c);

// display.c
int display_error(char *errorMessage);
int display_help(void);
void show_client(client_ftp_t *client);

// send.c
char *my_strcat(char *s1, char *s2);
void send_response(int fd, int code, char *message);

// init_serv.c
serv_ftp_t *init_serv_struct(serv_ftp_t *serv, int port, char *path);
serv_t *init_server_default_error_return(serv_t *serv, int err, \
const char *msg);
serv_t *init_server_default(void);
void init_server(serv_ftp_t *serv);
serv_t init_empty_server(void);

// get_command.c
void handle_command(client_ftp_t *client, char *buffer, serv_ftp_t *serv);
void free_command(char **command);
char **parse_command(char *buffer);
void unknow_command(int fd);

// frees.c
void free_serv(serv_ftp_t *serv);

// calc_port.c
char **parse_str(char *buffer, char *delimiters);
uint16_t get_port(int fd);
uint16_t calc_port(char *str);

// client.c
client_ftp_t *init_new_client(void);
void quit_client(serv_ftp_t *serv, client_ftp_t *client);

// run.c
void init_run(serv_ftp_t *serv, client_ftp_t *clients[100]);
void reset_fds(serv_ftp_t *serv, client_ftp_t *clients[100]);
void accept_new_connection(serv_ftp_t *serv, client_ftp_t *clients[100], int i);
int handle_incoming_request(serv_ftp_t *serv,
client_ftp_t *clients[100], int i);
void check_incoming_request(serv_ftp_t *serv, client_ftp_t *clients[100]);

// run2.c
int buff_ends(char *buff);
void exec_request(serv_ftp_t *serv, client_ftp_t *clients[100], int i);
void check_incoming_servers(serv_ftp_t *serv, client_ftp_t *clients[100]);

#endif /* !MY_FTP_H_ */
