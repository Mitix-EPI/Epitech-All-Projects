/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** player
*/

#include "../include/my.h"

void draw_player(tetris_t *tetris, WINDOW *a)
{
    int s = tetris->id;
    int y = tetris->tetrimino[s].y;
    int x = tetris->tetrimino[s].x;
    char **tetr = tetris->tetrimino[s].type;
    int start = (tetris->col / 2) - (x / 2);

    if (start < 1) {
        tetris->tetrimino_selected = 0;
        return;
    }
    for (int i = 0, i2 = 1; i < y; i++, i2++) {
        for (int j = start, count = 0; count < x &&
        tetr[i2][count]; count++, j++) {
            if (tetr[i2][count] == '*')
                tetris->map[i][j] = 'P';
            if (tetr[i2][count] == ' ')
                tetris->map[i][j] = 'S';
        }
    }
}

void freeze_player(tetris_t *tetris)
{
    for (int i = 0; tetris->map[i] != NULL; i++)
        for (int j = 0; tetris->map[i][j]; j++) {
            if (tetris->map[i][j] == 'S')
                tetris->map[i][j] = '0';
            if (tetris->map[i][j] == 'P')
                tetris->map[i][j] = '*';
        }
}

int check_player_touch(tetris_t *tetris)
{
    int res = 0;

    for (int i = 0; tetris->map[i] != NULL; i++)
        for (int j = 0; tetris->map[i][j]; j++)
            if (tetris->map[i][j] == 'P' &&
            (i == tetris->row - 1 || tetris->map[i + 1][j] == '*'))
                res = 1;
    if (res == 1) {
        freeze_player(tetris);
        tetris->tetrimino_selected = 0;
        return (1);
    }
    return (0);
}