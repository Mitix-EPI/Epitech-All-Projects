/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** list
*/

#include "generic_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool list_is_empty(list_t list)
{
    if (!list) {
        return true;
    }
    return false;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (node_t *tmp = list; tmp; tmp = tmp->next) {
        val_disp(tmp->value);
    }
}

void list_clear(list_t *front)
{
    (*front) = NULL;
}
