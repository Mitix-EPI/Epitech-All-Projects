/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** chained_list2
*/

#include "server/myteams.h"

list_replies_t *add_reply_at_the_end(reply_t repl, list_replies_t *strct)
{
    list_replies_t *head = malloc(sizeof(*head));
    list_replies_t *tmp = strct;

    head->_reply = repl;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

list_threads_t *add_thread_at_the_end(thread_t thrd, list_threads_t *strct)
{
    list_threads_t *head = malloc(sizeof(*head));
    list_threads_t *tmp = strct;

    head->_thread = thrd;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}

list_subteam_t *add_subteam_at_the_end(user_team_t usr_team_linkd, \
list_subteam_t *strct)
{
    list_subteam_t *head = malloc(sizeof(*head));
    list_subteam_t *tmp = strct;

    head->_usr_team_linked = usr_team_linkd;
    head->next = NULL;
    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}
