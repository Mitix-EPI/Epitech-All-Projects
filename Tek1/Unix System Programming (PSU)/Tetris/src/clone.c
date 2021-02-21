/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** clone
*/

#include "../include/my.h"

void down_all_lines_above(char **map, int i)
{
    for (; i > 0; i--) {
        for (int j = 0; map[i][j]; j++) {
            map[i][j] = map[i - 1][j];
        }
    }
}