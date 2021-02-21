/*
** EPITECH PROJECT, 2019
** my_charcat
** File description:
** Cat char
*/

#include "my.h"

char    *my_charcat(char *dest, char const src)
{
    int dest_size = my_strlen(dest);

    dest[dest_size] = src;
    dest[dest_size + 1] = '\0';
    return (dest);
}