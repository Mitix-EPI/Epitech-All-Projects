/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** find_best_id
*/

#include "lemin.h"

static int is_already_taken(node_t *node, ants_t *ants, int *ants_number)
{
    for (int i = 0 ; i < *ants_number ; ++i) {
        if (ants[i].id == node->id && ants[i].moved != -1) {
            return (1);
        }
    }
    return (0);
}

int find_best_id(node_t *node, ants_t *ants, int *ants_number)
{
    link_t *list = node->list;
    int shortest = INT_MAX;
    int id = -1;

    for (; list != NULL; list = list->next) {
        if (list->node->id == 1)
            return (1);
        if (list->node->distance < shortest) {
            if (is_already_taken(list->node, ants, ants_number) == 0) {
                shortest = list->node->distance;
                id = list->node->id;
            }
        }
    }
    return (id);
}
