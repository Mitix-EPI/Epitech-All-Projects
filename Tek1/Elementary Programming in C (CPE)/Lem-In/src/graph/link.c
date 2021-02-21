/*
** EPITECH PROJECT, 2019
** link
** File description:
** link
*/

#include "lemin.h"

static link_t *new_link(node_t *node)
{
    link_t *link = malloc(sizeof(link_t));

    link->node = node;
    link->next = NULL;
    return (link);
}

void push_link(node_t *node, node_t *linked_node)
{
    link_t *tmp = node->list;

    if (node->list == NULL) {
        node->list = new_link(linked_node);
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_link(linked_node);
}

int count_link(link_t *list)
{
    int count = 0;
    link_t *tmp = list;

    while (tmp != NULL) {
        tmp = tmp->next;
        ++count;
    }
    return (count);
}