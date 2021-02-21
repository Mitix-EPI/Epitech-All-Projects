/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_realloc
*/

#include "lemin.h"

char *my_realloc(char *str, int n)
{
    char *new_str = malloc(sizeof(char) * (n + 1));

    new_str[n] = '\0';
    for (int i = 0; str[i]; i += 1)
        new_str[i] = str[i];
    free(str);
    return (new_str);
}