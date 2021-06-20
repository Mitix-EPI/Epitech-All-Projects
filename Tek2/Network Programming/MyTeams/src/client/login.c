/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** login
*/

#include "client/myteams.h"

void wait_login_res(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    login_res(cli, parse_command(tmp));
}

void login_func(client_t *cli, char **command)
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
    if (cli->is_logged == 1) {
        printf("Already logged.\n");
        return;
    }
    command[1]++;
    command[1][strlen(command[1]) - 1] = 0;
    snprintf(buf, sizeof(buf), "%s %s\r\n", "login", command[1]);
    strncpy(cli->user_name, command[1], MAX_NAME_LENGTH);
    write(cli->sock, buf, strlen(buf));
    wait_login_res(cli);
}

void login_res(client_t *cli, char **command)
{
    if (strcmp(command[1], "success") == 0) {
        cli->is_logged = 1;
        strncpy(cli->uuid, command[2], 37);
        client_event_logged_in(command[2], cli->user_name);
    } else if (len_command(command) == 3) {
        client_event_logged_in(command[1], command[2]);
    } else {
        printf("Login error\n");
    }
}
