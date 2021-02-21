/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string into another
*/

#include "lemin.h"

char *my_strcpy(const char *src)
{
    const int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i = 0;

    dest[len] = '\0';
    for (i = 0; src[i]; i += 1)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}