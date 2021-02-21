/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_row_and_col
*/

#include "../include/my.h"

int get_row_and_col(tetris_t *tetris, char *optarg)
{
    char *str1 = my_strdup(optarg);
    char *str2 = NULL;
    int i = 0;
    int len = my_strlen(optarg);
    int count = 0;

    for (i = 0; optarg[i]; i++) {
        if ((optarg[i] < 48 || optarg[i] > 57) && optarg[i] != ',')
            return (84);
        if (optarg[i] == ',')
            count += 1;
    }
    if (count != 1)
        return (84);
    for (i = 0; optarg[i] && optarg[i] != ','; i++);
    str2 = my_strdup(&optarg[i + 1]);
    for (; i < len; i++)
        str1[i] = 0;
    tetris->row = my_getnbr(str1);
    tetris->col = my_getnbr(str2);
    return (0);
}