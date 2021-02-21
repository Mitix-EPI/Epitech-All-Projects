/*
** EPITECH PROJECT, 2020
** handling path
** File description:
** functions to set path structure and check errors
*/

#include "lemin.h"

void init_path(paths_t *path)
{
    path->debug = malloc(sizeof(char *) * 1);
    path->nodes = malloc(sizeof(char *) * 1);
    path->links = malloc(sizeof(char *) * 1);
    path->debug[0] = NULL;
    path->nb_rooms = 0;
    path->nodes[0] = NULL;
    path->links[0] = NULL;
    path->start = NULL;
    path->end = NULL;
    path->ants_number = 0;
}

int handling_path(paths_t *path)
{
    if (!path->start || !path->end || path->ants_number <= 0)
        return (0);
    if (!path->links[0]) {
        return (0);
    }
    return (1);
}