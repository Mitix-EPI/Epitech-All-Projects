/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare two strings
*/

#include "lemin.h"

int my_strncmp(char *check, char *verif, int start, int len)
{
    int i = start;

    if (!check || !verif)
        return (0);
    for (; verif[i] && check[i] && i < start + len; i += 1)
        if (verif[i] != check[i])
            return (0);
    return (1);
}

int my_strcmp(char *check, char *verif)
{
    int len_check = my_strlen(check);
    int len_verif = my_strlen(verif);

    if (len_check != len_verif)
        return (0);
    for (int i = 0; check[i]; i += 1)
        if (check[i] != verif[i])
            return (0);
    return (1);
}