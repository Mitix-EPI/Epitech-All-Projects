/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copies a string in another
*/

#include "rpg.h"

char *my_strcpy(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlength(src) + 1));

    dest[my_strlength(src)] = '\0';
    for (int i = 0; src[i]; i += 1)
        dest[i] = src[i];
    return (dest);
}