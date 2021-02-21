/*
** EPITECH PROJECT, 2019
** my_charcat
** File description:
** Cat char
*/

#include "my.h"

char    *my_char_tostring(char const src)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = src;
    str[1] = '\0';
    return (str);
}