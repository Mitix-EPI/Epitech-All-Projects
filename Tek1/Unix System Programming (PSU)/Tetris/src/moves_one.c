/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** moves_one
*/

#include "../include/my.h"

void cleanduplicate_l(tetris_t *tetris, vector_t start, vector_t tetri, int id)
{
    int y = 1;
    int x = 0;
    int x_map = start.x;
    start.x = start.x - 1;
    for (int y_map = start.y; tetris->tetrimino[id].type[y] != NULL &&
    tetris->tetrimino[id].type[y][0]; y++, y_map++) {
        for (x_map = start.x, x = 0; tetris->tetrimino[id].type[y][x] && x <
        tetris->tetrimino[id].x; x++, x_map++)
            if ((tetris->map[y_map][x_map] == 'P' &&
            tetris->tetrimino[id].type[y][x] != '*') ||
            (tetris->map[y_map][x_map] == 'S' &&
            tetris->tetrimino[id].type[y][x] != ' '))
                tetris->map[y_map][x_map] = '0';
        for (; tetris->map[y_map][x_map]; x_map++)
            if (tetris->map[y_map][x_map] == 'P' ||
            tetris->map[y_map][x_map] == 'S')
                tetris->map[y_map][x_map] = '0';
    }
}

int cant_go_left(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j]; j++)
            if (map[i][j] == 'P' && (j == 0 || map[i][j - 1] == '*'))
                return (1);
    }
    return (0);
}

void move_left(tetris_t *tetris)
{
    int id = tetris->id;
    vector_t start_map = return_p_x_position(tetris->map);
    vector_t start_tetri = return_p_x_position(tetris->tetrimino[id].type);
    int x = start_tetri.x;
    int y = 1;
    int count = 0;
    if (cant_go_left(tetris->map))
        return;
    for (int i = tetris->row - 1; i >= 0; i--) {
        for (int j = 0; tetris->map[i][j + 1]; j++) {
            if (tetris->map[i][j + 1] == 'P' && tetris->map[i][j] != '*')
                tetris->map[i][j] = 'P';
            if (tetris->map[i][j + 1] == 'S' && tetris->map[i][j] != '*')
                tetris->map[i][j] = 'S';
        }
    }
    cleanduplicate_l(tetris, start_map, start_tetri, id);
}