/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** messages
*/

#include <server/myteams.h>

int messages_error_handling(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};
    int isExist = is_user_exists(s, command[2]);
    if (!isExist) {
        snprintf(buf, sizeof(buf), "%s %s %s\r\n", "messages", \
        command[2], "user_unknown");
        write(cli->_socket, buf, strlen(buf));
        return (1);
    } else if (len_command(command) != 3) {
        printf("Internal error MESSAGES\n");
        snprintf(buf, sizeof(buf), "%s %s %s\r\n", "messages", \
        command[2], "error");
        write(cli->_socket, buf, strlen(buf));
        return (1);
    }
    return (0);
}

void messages_join(list_messages_t *tmp, char **command, char *buffer, \
char *buf)
{
    for (; tmp; tmp = tmp->next) {
        if ((strncmp(tmp->msg._sender_uuid, command[1], 37) == 0 \
        && strncmp(tmp->msg._receiver_uuid, command[2], 37) == 0)
        || (strncmp(tmp->msg._sender_uuid, command[2], 37) == 0
        && strncmp(tmp->msg._receiver_uuid, command[1], 37) == 0)) {
            snprintf(buf, 4096, " \"%s,%ld,%s\" ", \
            tmp->msg._sender_uuid, tmp->msg._time, tmp->msg._body);
            strcat(buffer, buf);
        }
    }
}

void messages_func(server_t *s, client_t *cli, char **command)
{
    char buffer[16384] = {0};
    char buf[4096] = {0};
    list_messages_t *tmp = s->_msgs;
    if (strcmp(command[2], cli->_uuid) == 0) {
        snprintf(buffer, sizeof(buffer), "%s %s", "messages", "error");
    } else if (!messages_error_handling(s, cli, command)) {
        snprintf(buffer, sizeof(buffer), "%s", "messages");
        messages_join(tmp, command, buffer, buf);
    }
    strcat(buffer, "\r\n");
    write(cli->_socket, buffer, strlen(buffer));
}