/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** list
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_list.h"

bool double_list_is_empty(double_list_t list)
{
    if (!list) {
        return true;
    }
    return false;
}

void double_list_dump(double_list_t list)
{
    for (doublelist_node_t *tmp = list; tmp; tmp = tmp->next) {
        printf("%f\n", tmp->value);
    }
}
