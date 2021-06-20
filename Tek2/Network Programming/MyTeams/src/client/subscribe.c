/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** subscribe
*/

#include "client/myteams.h"

void wait_subscribe_res(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    subscribe_res(cli, parse_command(tmp));
}

void subscribe_func(client_t *cli, char **command)
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
    if (cli->is_logged == 0) {
        printf("Not logged.\n");
        return;
    }
    command[1]++;
    command[1][strlen(command[1]) - 1] = 0;
    snprintf(buf, sizeof(buf), "%s %s\r\n", "subscribe", command[1]);
    write(cli->sock, buf, strlen(buf));
    wait_subscribe_res(cli);
}

void subscribe_res(client_t *cli, char **command)
{
    if (strcmp(command[1], "success") == 0) {
        cli->subteam = add_subteam_at_the_end(command[2], cli->subteam);
        client_print_subscribed(cli->uuid, command[2]);
    } else if (strcmp(command[1], "already_subscribed") == 0) {
        return;
    } else {
        client_error_unknown_team(command[2]);
        printf("Subscribe error\n");
    }
}
