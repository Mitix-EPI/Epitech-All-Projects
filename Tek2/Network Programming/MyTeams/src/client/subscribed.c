/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** subscribed
*/

#include "client/myteams.h"

void wait_subscribed_res(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    subscribed_res(cli, parse_command(tmp));
}

void all_subscribed_teams_client(client_t *cli)
{
    char buf[1060] = {0};
    snprintf(buf, sizeof(buf), "%s\r\n", "subscribed");
    write(cli->sock, buf, strlen(buf));
    wait_subscribed_res(cli);
}

void all_users_team(client_t *cli, char *team_uuid)
{
    char buf[1060] = {0};
    snprintf(buf, sizeof(buf), "%s %s\r\n", "subscribed", team_uuid);
    write(cli->sock, buf, strlen(buf));
    wait_subscribed_res(cli);
}

void subscribed_func(client_t *cli, char **command)
{
    if (len_command(command) > 2) {
        printf("Not good number of args.\n");
        return;
    }
    if (len_command(command) == 1)
        return (all_subscribed_teams_client(cli));
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
    all_users_team(cli, command[1]);
}

void subscribed_res(client_t *cli, char **command)
{
    if (strcmp(command[1], "all_users_sub_team") == 0) {
        subscribed_all_users_sub_team(cli, command);
        return;
    }
    if (strcmp(command[1], "all_teams_subed") == 0) {
        subscribed_all_teams_subed(cli, command);
        return;
    }
    if (strcmp(command[1], "error") == 0) {
        client_error_unknown_team(command[2]);
        printf("Subscribed error\n");
        return;
    }
    printf("INTERNAL ERROR SUBSCRIBED\n");
}
