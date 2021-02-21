/*
** EPITECH PROJECT, 2019
** node
** File description:
** node
*/

#include "lemin.h"

node_t *new_node(const char *name)
{
    static int id = 0;
    node_t *node = malloc(sizeof(node_t));

    node->name = my_strcpy(name);
    node->id = id++;
    node->distance = -1;
    node->list = NULL;
    return (node);
}

node_t *get_node(char *name, node_t **node)
{
    for (int i = 0 ; node[i] != NULL ; ++i)
        if (my_strcmp(node[i]->name, name) == 1)
            return (node[i]);
    return (NULL);
}

node_t *get_node_from_id(int id, node_t **node)
{
    for (int i = 0 ; node[i] != NULL ; ++i)
        if (node[i]->id == id)
            return (node[i]);
    return (NULL);
}

void free_node(node_t *node)
{
    link_t *lk = node->list;
    link_t *lk_del = NULL;

    while (lk) {
        lk_del = lk;
        lk = lk->next;
        free(lk_del);
    }
    free(node->name);
    free(node);
}

void free_nodes(node_t **nodes)
{
    for (int i = 0; nodes[i]; i++)
        free_node(nodes[i]);
    free(nodes);
}
