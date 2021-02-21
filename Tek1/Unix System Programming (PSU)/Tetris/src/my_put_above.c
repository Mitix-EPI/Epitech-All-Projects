/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_put_above
*/

#include "../include/my.h"

int count_arr(char **dest)
{
    int i = 0;

    for (; dest[i] != NULL; i++);
    return (i);
}

char **my_put_above(char **dest, char *src)
{
    int len = count_arr(dest);
    char **arr = malloc(sizeof(char *) * ((len + 2) + 1));
    for (int i = 0; i <= len + 2; i++)
        arr[i] = NULL;

    arr[0] = my_strdup(src);
    for (int i1 = 1, i2 = 0; i2 < len; i1++, i2++) {
        arr[i1] = malloc(sizeof(char) * (my_strlen(dest[i2]) + 1) + 1);
        fill_str(arr[i1], '\0', (my_strlen(dest[i2]) + 1));
        for (int j = 0; dest[i2][j] != 0; j++)
            arr[i1][j] = dest[i2][j];
    }
    return (arr);
}