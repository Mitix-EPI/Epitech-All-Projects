/*
** EPITECH PROJECT, 2019
** my_list_size
** File description:
** Return size of list
*/

#include "mylist.h"
#include "my.h"

int    my_list_size(linked_list_t const *begin)
{
    int size = 0;
    linked_list_t const *temp;

    temp = begin;
    while (temp != NULL) {
        size += 1;
        temp = temp->next;
    }
    return (size);
}
