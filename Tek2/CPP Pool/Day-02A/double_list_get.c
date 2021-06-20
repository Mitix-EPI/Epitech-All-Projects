/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** get
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    int i = 0;

    for (doublelist_node_t *tmp = list; tmp; tmp = tmp->next, i++);
    return i;
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (!list)
        return 0;
    return list->value;
}

double double_list_get_elem_at_back(double_list_t list)
{
    doublelist_node_t *tmp = NULL;

    if (!list)
        return 0;
    tmp = list;
    for (; tmp->next; tmp = tmp->next);
    return tmp->value;
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    doublelist_node_t *tmp = list;

    if (!list)
        return 0;
    if (position == 0)
        return double_list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position && tmp; i++, tmp = tmp->next);
    if (!tmp)
        return 0;
    return tmp->value;
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    doublelist_node_t *tmp = NULL;

    if (!list)
        return NULL;
    tmp = list;
    for (; tmp->value != value && tmp->next; tmp = tmp->next);
    if (!tmp->next && tmp->value != value) {
        return NULL;
    } else {
        return tmp;
    }
}
