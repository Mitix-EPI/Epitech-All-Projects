/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_strcat
*/

#include "../include/my.h"

int my_count_str(char const *dest)
{
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int nb_dest = my_count_str(dest);
    int nb_src = my_count_str(src);
    int i = 0;
    char *res = malloc(sizeof(res) * (nb_dest + nb_src) + 2);

    for (; dest[i]; i++)
        res[i] = dest[i];
    if (dest[nb_dest - 1] != '/') {
        res[i] = '/';
        i++;
    }
    for (int y = 0; src[y]; i++, y++)
        res[i] = src[y];
    res[i] = 0;
    return (res);
}
