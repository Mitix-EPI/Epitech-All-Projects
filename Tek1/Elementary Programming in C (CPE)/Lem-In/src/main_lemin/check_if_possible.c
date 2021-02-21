/*
** EPITECH PROJECT, 2020
** $
** File description:
** check_if_possible
*/

#include "lemin.h"

static int recursive_check(node_t *node, int depth, const int *max, int *tmp)
{
    link_t *list = node->list;

    if (*tmp == 1)
        return (1);
    if (depth < *max) {
        for (; list != NULL; list = list->next) {
            if (list->node->id == 1)
                *tmp = 1;
            recursive_check(list->node, depth + 1, max, tmp);
        }
    }
    return (0);
}

int check_if_possible(paths_t *path, node_t *node)
{
    const int nb_nodes = path->nb_rooms + 2;
    int tmp = 0;

    recursive_check(node, 0, &nb_nodes, &tmp);
    if (tmp == 1) {
        return (1);
    } else {
        return (0);
    }
}