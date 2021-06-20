/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** messages
*/

#include <client/myteams.h>

void wait_messages_func(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    messages_res(cli, parse_command(tmp));
}

void messages_func(client_t *cli, char **command)
{
    char buf[1060] = {0};
    if (len_command(command) != 2) {
        printf("Not good number of args.\n");
        return;
    }
    if (check_quote(command[1])) {
        printf("Argument must be in quote.\n");
        return;
    }
    if (cli->is_logged != 1) {
        client_error_unauthorized();
        return;
    }
    command[1]++;
    command[1][strlen(command[1]) - 1] = 0;
    snprintf(buf, sizeof(buf), "%s %s %s\r\n", "messages", \
    cli->uuid, command[1]);
    write(cli->sock, buf, strlen(buf));
    wait_messages_func(cli);
}

void messages_res(client_t *cli, char **command)
{
    char *token[3];

    (void) cli;
    if (len_command(command) == 2 && strcmp(command[1], "error") == 0) {
        printf("Messages error\n");
    } else if (len_command(command) == 3 &&
    strcmp(command[2], "user_unknown") == 0) {
        client_error_unknown_user(command[1]);
    } else {
        for (size_t i = 1; command && command[i] != NULL; i++) {
            token[0] = strtok(command[i], ",");
            token[1] = strtok(NULL, ",");
            token[2] = strtok(NULL, "\"");
            token[0]++;
            client_private_message_print_messages(token[0], \
            atoi(token[1]), token[2]);
        }
    }
}