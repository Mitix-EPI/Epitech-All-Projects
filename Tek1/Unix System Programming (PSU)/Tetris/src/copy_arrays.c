/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** copy_arrays
*/

#include "../include/my.h"

int count_y(char **str)
{
    int i = 0;

    for (; str[i] != NULL; i++);
    return (i);
}

char **copy_arrays(char **dest, char **src)
{
    int len = count_y(src);
    int count = 0;

    dest = malloc(sizeof(char *) * (len + 1));
    dest[len] = NULL;
    for (int i = 0; src[i] != NULL; i++) {
        dest[i] = my_strdup(src[i]);
    }
    return (dest);
}