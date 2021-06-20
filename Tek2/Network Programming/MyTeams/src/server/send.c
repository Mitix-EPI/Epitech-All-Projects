/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** send
*/

#include "server/myteams.h"

int is_user_exists(server_t *s, char *uuid)
{
    list_users_t *tmp = s->_users;

    for (; tmp; tmp = tmp->next)
        if (strcmp(tmp->usr._uuid, uuid) == 0)
            return (1);
    return (0);
}

int get_user_by_uuid(server_t *s, char *uuid)
{
    for (int i = 0; i < s->_max_client; i++)
        if (s->_c_list[i]._socket != NO_SOCKET)
            if (strcmp(s->_c_list[i]._uuid, uuid) == 0)
                return (s->_c_list[i]._socket);
    return (-1);
}

int send_error_handling(server_t *s, client_t *cli, char **command)
{
    char buf_exp[4096] = {0};
    int isExist = is_user_exists(s, command[2]);
    if (!isExist) {
        snprintf(buf_exp, sizeof(buf_exp), "%s %s %s\r\n", "send", \
        command[2], "user_unknown");
        write(cli->_socket, buf_exp, strlen(buf_exp));
        return (1);
    } else if (len_command(command) != 4) {
        printf("Internal error SEND\n");
        snprintf(buf_exp, sizeof(buf_exp), "%s %s %s\r\n", "send", \
        command[2], "error");
        write(cli->_socket, buf_exp, strlen(buf_exp));
        return (1);
    }
    return (0);
}

message_t fill_message(char **command)
{
    message_t msg;

    strncpy(msg._sender_uuid, command[1], 37);
    strncpy(msg._receiver_uuid, command[2], 37);
    strncpy(msg._body, command[3], MAX_BODY_LENGTH);
    msg._time = time(NULL);
    return (msg);
}

void send_func(server_t *s, client_t *cli, char **command)
{
    char buf_exp[4096] = {0};
    char buf_dest[4096] = {0};
    command[2]++;
    command[2][strlen(command[2]) - 1] = 0;
    command[3]++;
    command[3][strlen(command[3]) - 1] = 0;
    int dest_sock = get_user_by_uuid(s, command[2]);

    if (!send_error_handling(s, cli, command)) {
        server_event_private_message_sended(command[1], command[2], \
        command[3]);
        message_t msg = fill_message(command);
        s->_msgs = add_messages_at_the_end(msg, s->_msgs);
        snprintf(buf_dest, sizeof(buf_dest), "%s \"%s\" \"%s\"\r\n", \
        "send", command[1], command[3]);
        if (dest_sock != -1)
            write(dest_sock, buf_dest, strlen(buf_dest));
        snprintf(buf_exp, sizeof(buf_exp), "%s %s\r\n", "send", "success");
        write(cli->_socket, buf_exp, strlen(buf_exp));
    }
}
