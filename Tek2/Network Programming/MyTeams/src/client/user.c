/*
** EPITECH PROJECT, 2021
** user
** File description:
** file
*/

#include "client/myteams.h"

void wait_user_func(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    user_res(cli, parse_command(tmp));
}

void user_func(client_t *cli, char **command)
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
    snprintf(buf, sizeof(buf), "%s %s\r\n", "user", command[1]);
    write(cli->sock, buf, strlen(buf));
    wait_user_func(cli);
}

user_data_t parse_user(char **command)
{
    user_data_t data;

    strncpy(data.uuid, command[1], 37);
    strncpy(data.username, command[2], MAX_NAME_LENGTH);
    data.sts = command[3][0] - 48;
    return (data);
}

void user_res(client_t *cli, char **command)
{
    (void) cli;
    if (strcmp(command[2], "error") == 0) {
        client_error_unknown_user(command[1]);
    } else {
        user_data_t usr = parse_user(command);
        client_print_user(usr.uuid, usr.username, usr.sts);
    }
}
