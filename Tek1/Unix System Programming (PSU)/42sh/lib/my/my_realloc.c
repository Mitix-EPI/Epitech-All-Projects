/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** Realloc
*/

#include "my.h"

char    *my_realloc(char *p, int size)
{
    char *p2 = malloc(size);

    my_memset(p2, 0, size);
    my_strcpy(p2, p);
    return (p2);
}