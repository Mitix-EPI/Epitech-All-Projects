/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** chained_list_users
*/

#include "client/myteams.h"

users_list_t *add_user_at_the_end(user_data_t usr, users_list_t *strct)
{
    users_list_t *head = malloc(sizeof(*head));
    users_list_t *tmp = strct;

    head->usr = usr;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

teams_list_t *add_teamslist_at_the_end(team_data_t team, teams_list_t *strct)
{
    teams_list_t *head = malloc(sizeof(*head));
    teams_list_t *tmp = strct;

    head->team = team;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

subteam_list_t *add_subteam_at_the_end(char *team_uuid, subteam_list_t *strct)
{
    subteam_list_t *head = malloc(sizeof(*head));
    subteam_list_t *tmp = strct;

    strncpy(head->_team_uuid, team_uuid, 37);
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

void reversed_display(users_list_t *head)
{
    users_list_t *tmp = head;

    if (!tmp)
        return;
    if (tmp)
        reversed_display(tmp->next);
    printf("%s", tmp->usr.username);
    printf(" / ");
    printf("%s", tmp->usr.uuid);
    printf("/ %d", tmp->usr.sts);
    printf("\n");
}

int exist_node(char *name, users_list_t *head)
{
    users_list_t *tmp = head;

    for (; tmp; tmp = tmp->next) {
        if (strcmp(tmp->usr.username, name) == 0) {
            return (1);
        }
    }
    return (0);
}
