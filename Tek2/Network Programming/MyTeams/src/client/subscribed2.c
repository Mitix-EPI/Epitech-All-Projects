/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** subscribed2
*/

#include "client/myteams.h"

teams_list_t *parse_teams_data(char **command)
{
    teams_list_t *teamsList = NULL;

    for (size_t i = 2; command && command[i] != NULL; i++) {
        char name[MAX_NAME_LENGTH] = {0};
        char uuid[37] = {0};
        char descr[MAX_DESCRIPTION_LENGTH] = {0};
        get_uuid(command[i], uuid);
        get_username(command[i], name);
        get_description(command[i], descr);
        remove_quotes_sub(name);
        remove_quotes_sub(descr);
        team_data_t team;
        strncpy(team.uuid, uuid, 37);
        strncpy(team.name, name, MAX_NAME_LENGTH);
        strncpy(team.descr, descr, MAX_DESCRIPTION_LENGTH);
        teamsList = add_teamslist_at_the_end(team, teamsList);
    }
    return (teamsList);
}

void free_teams_list(teams_list_t *teamsList)
{
    if (!teamsList)
        return;
    if (teamsList)
        free_teams_list(teamsList->next);
    free(teamsList);
}

void subscribed_all_users_sub_team(client_t *cli, char **command)
{
    (void) cli;
    users_list_t *usersList = parse_users_data(command);
    users_list_t *tmp = usersList;

    while (tmp) {
        client_print_users(tmp->usr.uuid, tmp->usr.username, tmp->usr.sts);
        tmp = tmp->next;
    }
    free_users_list(usersList);
}

void subscribed_all_teams_subed(client_t *cli, char **command)
{
    (void) cli;
    teams_list_t *teamsList = parse_teams_data(command);
    teams_list_t *tmp = teamsList;

    while (tmp) {
        client_print_team(tmp->team.uuid, tmp->team.name, tmp->team.descr);
        tmp = tmp->next;
    }
    free_teams_list(teamsList);
}
