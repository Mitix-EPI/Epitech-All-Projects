/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** create_map
*/

#include "../include/my.h"

char **create_map(tetris_t *tetris)
{
    int y = tetris->row;
    int x = tetris->col;
    char **map = malloc(sizeof(char *) * (y + 1));

    map[y] = NULL;
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        map[i][x] = 0;
        for (int j = 0; j < x; j++)
            map[i][j] = '0';
    }
    return (map);
}