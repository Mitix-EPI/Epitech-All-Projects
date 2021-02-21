/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** moves
*/

#include "../include/my.h"

int cant_go_right(char **map, int col)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j]; j++)
            if (map[i][j] == 'P' && (j == col - 1 || map[i][j + 1] == '*'))
                return (1);
    }
    return (0);
}

void cleanduplicate_r(tetris_t *tetris, vector_t start, vector_t tetri, int id)
{
    int y = 1;
    int x = 0;
    int x_map = start.x;
    for (int i = start.y, j = start.x; tetris->map[i] != NULL; i++)
        if (tetris->map[i][j] == 'P' || tetris->map[i][j] == 'S')
            tetris->map[i][j] = '0';
    start.x = start.x + 1;
    for (int y_map = start.y; tetris->tetrimino[id].type[y] != NULL &&
    tetris->tetrimino[id].type[y][0]; y++, y_map++) {
        for (x_map = start.x, x = 0; tetris->tetrimino[id].type[y][x] &&
        x < tetris->tetrimino[id].x; x++, x_map++)
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

void move_right(tetris_t *tetris)
{
    int id = tetris->id;
    vector_t start_map = return_p_x_position(tetris->map);
    vector_t start_tetri = return_p_x_position(tetris->tetrimino[id].type);
    int x = start_tetri.x;
    int y = 1;
    int count = 0;
    if (cant_go_right(tetris->map, tetris->col))
        return;
    for (int i = tetris->row - 1; i >= 0; i--) {
        for (int j = tetris->col; j > 0; j--) {
            if (tetris->map[i][j - 1] == 'P' && tetris->map[i][j] != '*')
                tetris->map[i][j] = 'P';
            if (tetris->map[i][j - 1] == 'S' && tetris->map[i][j] != '*')
                tetris->map[i][j] = 'S';
        }
    }
    cleanduplicate_r(tetris, start_map, start_tetri, id);
}

void go_down(tetris_t *tetris)
{
    int id = tetris->id;
    vector_t start_map = return_p_x_position(tetris->map);
    vector_t start_tetri = return_p_x_position(tetris->tetrimino[id].type);
    int x = start_tetri.x;
    int y = 1;
    int count = 0;
    for (int i = tetris->row - 1; i > 0; i--) {
        for (int j = 0; tetris->map[i][j]; j++) {
            if (tetris->map[i - 1][j] == 'P' && tetris->map[i][j] != '*')
                tetris->map[i][j] = 'P';
            if (tetris->map[i - 1][j] == 'S' && tetris->map[i][j] != '*')
                tetris->map[i][j] = 'S';
        }
    }
    clean_duplicate(tetris, start_map, start_tetri, id);
}

void move_down(tetris_t *tetris)
{
    while (1) {
        if (check_player_touch(tetris))
            break;
        go_down(tetris);
        if (check_player_touch(tetris))
            break;
    }
}