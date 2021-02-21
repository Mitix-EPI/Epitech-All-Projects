/*
** EPITECH PROJECT, 2019
** my_arr_insert
** File description:
** Insert arr
*/

#include "my.h"

void my_arr_insert(char ***arr, char *value)
{
    int len = 0;

    for (; (*arr)[len]; len++);
    (*arr) = realloc((*arr), sizeof(char *) * (len + 2));
    (*arr)[len] = value;
    (*arr)[len + 1] = NULL;
}

int my_arr_contain(char **arr, char *value)
{
    if (!arr || !value)
        return (0);
    for (int i = 0; arr[i]; i++) {
        if (!my_strcmp(arr[i], value))
            return (1);
    }
    return (0);
}