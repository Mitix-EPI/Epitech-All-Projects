/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** logout
*/

#include "client/myteams.h"

void wait_logout_res(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    logout_res(cli, parse_command(tmp));
}

void logout_func(client_t *cli, char **command)
{
    char buf[1060] = {0};
    if (len_command(command) != 1) {
        printf("Not good number of args.");
        return;
    }
    if (cli->is_logged != 1) {
        client_error_unauthorized();
    } else {
        snprintf(buf, sizeof(buf), "%s %s\r\n", "logout", cli->uuid);
        write(cli->sock, buf, strlen(buf));
    }
    wait_logout_res(cli);
}

void logout_res(client_t *cli, char **command)
{
    if (strcmp(command[1], "success") == 0) {
        cli->is_logged = 0;
        client_event_logged_out(cli->uuid, cli->user_name);
        memset(cli->uuid, 0, 37);
        memset(cli->user_name, 0, MAX_NAME_LENGTH);
        exit(0);
    } else if (len_command(command) == 3) {
        client_event_logged_out(command[1], command[2]);
    } else {
        printf("Logout error\n");
    }
}
