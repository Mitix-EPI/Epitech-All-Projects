/*
** EPITECH PROJECT, 2020
** link_all_nodes
** File description:
** link_all_nodes
*/

#include "lemin.h"

void link_all_nodes(paths_t *path, node_t **nodes)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    for (int i = 0; path->links[i]; i++) {
        tmp1 = my_str(path->links[i]);
        tmp2 = get_second_id(path->links[i]);
        for (int j = 0 ; nodes[j] ; ++j) {
            if (my_strcmp(nodes[j]->name, tmp1) == 1) {
                push_link(get_node(tmp1, nodes), get_node(tmp2, nodes));
            } else if (my_strcmp(nodes[j]->name, tmp2) == 1) {
                push_link(get_node(tmp2, nodes), get_node(tmp1, nodes));
            }
        }
        free(tmp1);
        free(tmp2);
    }
}
