/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** add
*/

#include "generic_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *newNode = malloc(sizeof(node_t));
    if (!newNode)
        return false;
    newNode->value = elem;
    newNode->next = (*front_ptr);
    (*front_ptr) = newNode;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *newNode = malloc(sizeof(node_t));
    node_t *tmp = NULL;

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

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    node_t *newNode = malloc(sizeof(node_t));
    node_t *tmp = (*front_ptr);
    if (!newNode)
        return false;
    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    newNode->value = elem;
    for (unsigned int i = 0; i < position - 1 && tmp; i++,
    tmp = tmp->next);
    if (!tmp)
        return false;
    newNode->next = tmp->next;
    tmp->next = newNode;
    return true;
}
