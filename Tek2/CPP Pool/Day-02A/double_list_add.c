/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** add
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_list.h"

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *newNode = malloc(sizeof(doublelist_node_t));

    if (!newNode)
        return false;
    newNode->value = elem;
    newNode->next = (*front_ptr);
    (*front_ptr) = newNode;
    return true;
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *newNode = malloc(sizeof(doublelist_node_t));
    doublelist_node_t *tmp = NULL;

    if (!newNode)
        return false;
    newNode->value = elem;
    newNode->next = NULL;
    if (!(*front_ptr)) {
        (*front_ptr) = newNode;
        return true;
    }
    tmp = (*front_ptr);
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return true;
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    doublelist_node_t *newNode = NULL;
    doublelist_node_t *tmp = (*front_ptr);

    if (position == 0)
        return double_list_add_elem_at_front(front_ptr, elem);
    newNode = malloc(sizeof(doublelist_node_t));
    if (!newNode)
        return false;
    newNode->value = elem;
    for (unsigned int i = 0; i < position - 1 && tmp; i++, tmp = tmp->next);
    if (!tmp)
        return false;
    newNode->next = tmp->next;
    tmp->next = newNode;
    return true;
}
