/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** loose
*/

#include "../include/my.h"

int loose(tetris_t *tetris)
{
    for (int x = 0; tetris->map[0][x]; x++)
        if (tetris->map[0][x] == '*') {
            tetris->loose = 1;
            return (1);
        }
    return (0);
}