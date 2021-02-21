/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** alphabetic_sort
*/

#include "../include/my.h"

char *the_future_of_malloc(char **tab)
{
    int max_len = my_strlen(tab[0]);
    char *str = NULL;

    for (int i = 1; tab[i] != NULL; i += 1)
        if (max_len < my_strlen(tab[i]))
            max_len = my_strlen(tab[i]);
    str = malloc(sizeof(char) * (max_len + 1));
    return (str);
}

int sorting(char **tab, char *str, int j, int change)
{
    int k = 0;

    for (;tab[j][k] == tab[j + 1][k]; k += 1) {
        k += 1;
        if (tab[j][k] > tab[j + 1][k]) {
            str = tab[j];
            tab[j] = tab[j + 1];
            tab[j + 1] = str;
            change = 1;
        }
    }
    return (change);
}

char **alpha_sort(char **tab)
{
    int sort = 0;
    int change = 0;
    char *str = NULL;

    while (sort != 1) {
        change = 0;
        for (int j = 0; tab[j + 1] != NULL; j += 1) {
            if (tab[j][0] > tab[j + 1][0]) {
                str = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = str;
                change = 1;
            } else if (tab[j][0] == tab[j + 1][0])
                sorting(tab, str, j, change);
        }
        if (change == 0)
            sort = 1;
    }
    return (tab);
}