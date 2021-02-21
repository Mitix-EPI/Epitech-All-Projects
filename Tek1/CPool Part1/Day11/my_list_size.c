/*
** EPITECH PROJECT, 2019
** my_list_size.c
** File description:
** return value
*/

#include "include/mylist.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *list;
    int i = 0;

    list = begin;
    while (begin != NULL) {
        list = list->next;
        i++;
    }
    return (i);
}
