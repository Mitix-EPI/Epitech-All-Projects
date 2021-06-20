/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** chained_list
*/

#include "server/myteams.h"

list_users_t *add_node_at_the_end(user_t usr, list_users_t *strct)
{
    list_users_t *head = malloc(sizeof(*head));
    list_users_t *tmp = strct;

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

void reversed_display(list_users_t *head)
{
    list_users_t *tmp = head;

    if (!tmp)
        return;
    if (tmp)
        reversed_display(tmp->next);
    printf("%s", tmp->usr._username);
    printf(" / ");
    printf("%s", tmp->usr._uuid);
    printf("\n");
}

int exist_node(char *name, list_users_t *head)
{
    list_users_t *tmp = head;

    for (; tmp; tmp = tmp->next) {
        if (strcmp(tmp->usr._username, name) == 0) {
            return (1);
        }
    }
    return (0);
}

list_channels_t *add_channel_at_the_end(channel_t chnl, \
list_channels_t *strct)
{
    list_channels_t *head = malloc(sizeof(*head));
    list_channels_t *tmp = strct;

    head->_channel = chnl;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

list_teams_t *add_team_at_the_end(team_t team, list_teams_t *strct)
{
    list_teams_t *head = malloc(sizeof(*head));
    list_teams_t *tmp = strct;

    head->_team = team;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}
