/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** send
*/

#include "client/myteams.h"

void wait_send_func(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    send_res(cli, parse_command(tmp));
}

void send_func(client_t *cli, char **command)
{
    char buf[1060] = {0};
    if (len_command(command) != 3) {
        printf("Not good number of args.\n");
        return;
    }
    if (check_quote(command[1]) && check_quote(command[2])) {
        printf("Argument must be in quote.\n");
        return;
    }
    if (cli->is_logged != 1) {
        client_error_unauthorized();
        return;
    }
    snprintf(buf, sizeof(buf), "%s %s %s %s\r\n", "send", cli->uuid, \
    command[1], command[2]);
    write(cli->sock, buf, strlen(buf));
    wait_send_func(cli);
}

void send_res(client_t *cli, char **command)
{
    (void) cli;
    if (strcmp(command[1], "success") == 0) {
        printf("Message sent\n");
        return;
    }
    if (strcmp(command[2], "user_unknown") == 0) {
        client_error_unknown_user(command[1]);
        return;
    }
    if (strcmp(command[2], "error") == 0) {
        printf("Send error\n");
    } else {
        command[1]++;
        command[1][strlen(command[1]) - 1] = 0;
        command[2]++;
        command[2][strlen(command[2]) - 1] = 0;
        client_event_private_message_received(command[1], command[2]);
    }
}
