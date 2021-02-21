/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fills
*/

#include <stdlib.h>

void fill_arr_null(char **arr, int size)
{
    for (int i = 0; i <= size; i++)
        arr[i] = NULL;
}

void fill_str(char *str, int len, char c)
{
    for (int i = 0; i <= len; i++)
        str[i] = c;
}
