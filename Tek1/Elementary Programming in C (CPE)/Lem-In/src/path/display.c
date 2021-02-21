/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "lemin.h"

void display_debug(paths_t *paths)
{
    for (int i = 0; paths->debug[i] != NULL; i += 1) {
        my_putstr(1, paths->debug[i]);
        my_putstr(1, "\n");
    }
    my_putstr(1, "#moves\n");
}