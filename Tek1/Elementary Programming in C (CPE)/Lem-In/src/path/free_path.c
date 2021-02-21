/*
** EPITECH PROJECT, 2020
** free_path
** File description:
** free_path
*/

#include "lemin.h"

void free_path(paths_t *path)
{
    free(path->start);
    free(path->end);
    for (int i = 0 ; path->nodes[i] ; ++i)
        free(path->nodes[i]);
    for (int i = 0 ; path->links[i] ; ++i)
        free(path->links[i]);
    for (int i = 0 ; path->debug[i] ; ++i)
        free(path->debug[i]);
    free(path);
}