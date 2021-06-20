/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** get
*/

#include "generic_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int list_get_size(list_t list)
{
    int i = 0;

    for (node_t *tmp = list; tmp; tmp = tmp->next, i++);
    return i;
}

void *list_get_elem_at_front(list_t list)
{
    if (!list)
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    node_t *tmp = NULL;

    if (!list)
        return 0;
    tmp = list;
    for (; tmp->next; tmp = tmp->next);
    return tmp->value;
}

void *list_get_elem_at_position(list_t list,
unsigned int position)
{
    node_t *tmp = list;

    if (!list)
        return 0;
    if (position == 0)
        return list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position && tmp; i++, tmp = tmp->next);
    if (!tmp)
        return 0;
    return tmp->value;
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    node_t *tmp = NULL;

    if (!list)
        return NULL;
    tmp = list;
    for (; val_comp(value, tmp->value) != 0; tmp = tmp->next);
    if (!tmp->next && val_comp(value, tmp->value) != 0) {
        return NULL;
    } else {
        return tmp;
    }
}
