/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** algorithm
*/

#include "lemin.h"

static ants_t *create_ants(int *ants_number)
{
    ants_t *ants = malloc(sizeof(ants_t) * *ants_number);

    for (int i = 0 ; i < *ants_number ; ++i) {
        ants[i].id = 0;
        ants[i].moved = 0;
    }
    return (ants);
}

void display_movement(ants_t *ants, int *ants_number, node_t **nodes, int *end)
{
    node_t *node = NULL;
    int count = 0;

    for (int i = 0; i < *ants_number; ++i) {
        if (ants[i].id != 0 && ants[i].moved == 1 && ants[i].id != -1) {
            if (count > 0)
                my_putstr(1, " ");
            my_putstr(1, "P");
            my_putnbr(i + 1);
            my_putstr(1, "-");
            node = get_node_from_id(ants[i].id, nodes);
            my_putstr(1, node->name);
            ++count;
        }
    }
    if (*end == 0)
        my_putstr(1, "\n");
}

static void next_step(node_t **nodes, ants_t *ants, paths_t *path)
{
    const int nb = path->ants_number;
    int tmp = 0;

    for (int i = 0 ; i < nb; ++i) {
        if (ants[i].moved != -1) {
            if (ants[i].id == 1) {
                ants[i].moved = -1;
                continue;
            }
            tmp = find_best_id(get_node_from_id(ants[i].id, nodes), ants,
            &path->ants_number);
            if (tmp != -1) {
                ants[i].id = tmp;
                ants[i].moved = 1;
            } else
                ants[i].moved = 0;
        }
    }
}

static int check_finish(ants_t *ants, int *ants_number)
{
    for (int i = 0; i < *ants_number; ++i)
        if (ants[i].moved != -1)
            return (0);
    return (1);
}

void algorithm(node_t **nodes, paths_t *path)
{
    init_nodes_distances(nodes, path);
    ants_t *ants = create_ants(&path->ants_number);

    int end = 0;
    for (; ; ) {
        next_step(nodes, ants, path);
        end = check_finish(ants, &path->ants_number);
        display_movement(ants, &path->ants_number, nodes, &end);
        if (end == 1)
            break;
    }
    free(ants);
}
