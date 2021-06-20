/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** messages_list
*/

#include "server/myteams.h"

list_messages_t *add_messages_at_the_end(message_t usr, list_messages_t *strct)
{
    list_messages_t *head = malloc(sizeof(*head));
    list_messages_t *tmp = strct;

    head->msg = usr;
    head->next = NULL;

    if (!strct)
        return (head);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return (strct);
}
