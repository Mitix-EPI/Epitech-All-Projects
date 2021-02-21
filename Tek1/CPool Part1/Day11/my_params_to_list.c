/*
** EPITECH PROJECT, 2019
** my_params_to_list.c
** File description:
** return value
*/

#include "include/mylist.h"
#include <stdlib.h>
#include <stddef.h>

void my_put_in_list(linked_list_t **list, char *data)
{
    linked_list_t *element;

    element = malloc(sizeof(element));
    element->data = data;
    element->next = *list;
    *list = element;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    int i = 0;

    list = NULL;
    while (i < ac) {
        my_put_in_list(&list, av[i]);
        i++;
    }
    return (list);
}
