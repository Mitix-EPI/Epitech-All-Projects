/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my_str
*/

#include "lemin.h"

int check_str(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) ||
    (c >= 97 && c <= 122)) {
        return (1);
    } else
        return (0);
}

char *my_str(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (str == NULL)
        return (NULL);
    new[len] = 0;
    for (; str[i] && check_str(str[i]); i++)
        new[i] = str[i];
    for (; str[i]; i++)
        new[i] = 0;
    return (new);
}