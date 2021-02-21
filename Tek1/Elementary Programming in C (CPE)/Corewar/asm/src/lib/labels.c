/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** label
*/

#include "asm.h"

void add_element_label(label_t **list, int pos, char *label)
{
    label_t *elem = malloc(sizeof(*elem));
    label_t *tmp = *list;

    int nb = 0;
    elem->byte_position = pos;
    elem->label_name = label;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element_label(label_t **list, int position)
{
    label_t *tmp1 = NULL;
    label_t *tmp2 = (*list);
    label_t *tmp_to_free = NULL;

    if (position == 1) {
        tmp1 = (*list);
        (*list) = (*list)->next;
        free(tmp1);
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp2 = tmp2->next;
    tmp1 = tmp2->next->next;
    tmp_to_free = tmp2->next;
    tmp2->next = tmp1;
    free(tmp_to_free);
}

void insert_element_label(label_t **list, int position, int pos, char *label)
{
    label_t *elem = malloc(sizeof(*elem));
    label_t *tmp1 = (*list);
    label_t *tmp2 = (*list);

    elem->byte_position = pos;
    elem->label_name = label;
    if (position == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
        if (i < position - 2 && tmp2 == NULL)
            exit(84);
    }
    tmp1->next = elem;
    elem->next = tmp2;
}

void destroy_list_label(label_t **list)
{
    label_t *tmp = (*list);

    for (; (*list); tmp = (*list)) {
        (*list) = (*list)->next;
        free(tmp->label_name);
        free(tmp);
    }
}

int get_size_list_label(label_t *list)
{
    int i = 0;

    for (; list; list = list->next, i += 1);
    return (i);
}