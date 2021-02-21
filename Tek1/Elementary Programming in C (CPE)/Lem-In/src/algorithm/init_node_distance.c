/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** init_node_distance
*/

#include "lemin.h"

static void recursive(node_t *node, const int depth, const int *max)
{
    link_t *list = node->list;

    if (depth < *max) {
        for (; list != NULL ; list = list->next) {
            if (node->distance == -1)
                node->distance = depth;
            if (depth <= node->distance)
                node->distance = depth;
            else
                continue;
            recursive(list->node, depth + 1, max);
        }
    }
    return;
}

void init_nodes_distances(node_t **nodes, paths_t *path)
{
    const int nb_nodes = path->nb_rooms + 2;

    recursive(nodes[1], 0, &nb_nodes);
}
