/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** nodes
*/

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void add_element(node_t **list, line_t line)
{
    node_t *elem = malloc(sizeof(*elem));
    node_t *tmp = *list;

    int nb = 0;
    elem->line = line;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element(node_t **list, int position)
{
    node_t *tmp1 = NULL;
    node_t *tmp2 = (*list);
    node_t *tmp_to_free = NULL;

    if (position == 1) {
        tmp1 = (*list);
        (*list) = (*list)->next;
        free(tmp1);
        return;
    }
    for (int i = 0; i < position - 2; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1 = tmp2->next->next;
    tmp_to_free = tmp2->next;
    tmp2->next = tmp1;
    free(tmp_to_free);
}

void insert_element(node_t **list, int position, line_t line)
{
    node_t *elem = malloc(sizeof(*elem));
    node_t *tmp1 = (*list);
    node_t *tmp2 = (*list);

    elem->line = line;
    if (position == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
        if (i < position - 2 && tmp2 == NULL) {
            printf("no way\n");
            exit(84);
        }
    }
    tmp1->next = elem;
    elem->next = tmp2;
}

void destroy_list(node_t **list)
{
    node_t *tmp = (*list);

    for (; (*list); tmp = (*list)) {
        (*list) = (*list)->next;
        free(tmp->line.type);
        for (int i = 0; tmp->line.arg[i]; i += 1)
            free(tmp->line.arg[i]);
        free(tmp->line.arg);
        free(tmp);
    }
}

int get_size_list(node_t *list)
{
    int i = 0;

    for (; list; list = list->next, i += 1);
    return (i);
}