/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** del
*/

#include "generic_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    if (!(*front_ptr))
        return false;
    (*front_ptr) = (*front_ptr)->next;
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *tmp = NULL;

    if (!(*front_ptr))
        return false;
    tmp = (*front_ptr);
    if (!(tmp->next))
        (*front_ptr) = NULL;
    for (; tmp->next->next; tmp = tmp->next);
    tmp->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t *front_ptr,
unsigned int position)
{
    node_t *tmp = (*front_ptr);

    if (!(*front_ptr))
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    for (unsigned int i = 0; i < position - 1 && tmp; i++, tmp = tmp->next);
    if (!tmp)
        return false;
    if (!tmp->next)
        return false;
    tmp->next = tmp->next->next;
    return true;
}
