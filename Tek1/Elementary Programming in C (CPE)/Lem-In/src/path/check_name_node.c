/*
** EPITECH PROJECT, 2020
** check name node
** File description:
** functions to check all names for node
*/

#include "lemin.h"

int compare_names(char *node, char *name, int index, int i)
{
    int ret = 0;

    if (index == i)
        return (0);
    if (my_strcmp(node, name))
        ret = 1;
    free(name);
    return (ret);
}

int check_this_node(int index, char *node, paths_t *path)
{
    char *name = NULL;

    for (int i = 0; path->nodes[i] != NULL; i += 1) {
        if (i == index)
            continue;
        name = my_str(path->nodes[i]);
        if (compare_names(node, name, index, 0))
            return (0);
    }
    name = my_str(path->start);
    if (compare_names(node, name, index, -1))
        return (0);
    name = my_str(path->end);
    if (compare_names(node, name, index, -2))
        return (0);
    return (1);
}

void check_name_node(paths_t *path)
{
    char *name_node = NULL;

    for (int i = 0; path->nodes[i] != NULL; i += 1) {
        name_node = my_str(path->nodes[i]);
        if (!check_this_node(i, name_node, path))
            path->ants_number = 0;
        free(name_node);
    }
    name_node = my_str(path->start);
    if (!check_this_node(-1, name_node, path))
        path->ants_number = 0;
    free(name_node);
    name_node = my_str(path->end);
    if (!check_this_node(-2, name_node, path))
        path->ants_number = 0;
    free(name_node);
}