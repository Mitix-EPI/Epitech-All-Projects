/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** gameplay_one
*/

#include "../include/my.h"

int generate_random(int l, int r)
{
    srand(time(NULL));
    return ((rand() % (r - l + 1)) + l);
}

void select_id_tetrimino(tetris_t *tetris)
{
    int res = 0;

    if (tetris->id_next < 0) {
        res = generate_random(1, my_strlen(tetris->good_tetr) - 1) - 1;
        tetris->id = tetris->good_tetr[res] - '0';
        tetris->tetrimino[tetris->id].type =
        copy_arrays(tetris->tetrimino[tetris->id].type,
        tetris->tetrimino[tetris->id].origin);

        res = generate_random(1, my_strlen(tetris->good_tetr) - 1) - 1;
        tetris->id_next = tetris->good_tetr[res] - '0';
    } else {
        tetris->id = tetris->id_next;
        tetris->tetrimino[tetris->id].type =
        copy_arrays(tetris->tetrimino[tetris->id].type,
        tetris->tetrimino[tetris->id].origin);
        res = generate_random(1, my_strlen(tetris->good_tetr) - 1) - 1;
        tetris->id_next = tetris->good_tetr[res] - '0';
    }
}

struct vector_s return_p_x_position(char **map)
{
    vector_t vector;
    for (int i = 0;  map[i] && map[i] != NULL && map[i][0]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == 'P' || map[i][j] == 'S') {
                vector.y = i;
                vector.x = j;
                return (vector);
            }
        }
    }
}

void clean_duplicate(tetris_t *tetris, vector_t start, vector_t tetri, int id)
{
    int y = 1;
    int x = 0;
    int x_map = start.x;
    for (int i = start.y, j = start.x; tetris->map[i][j]; j++)
        if (tetris->map[i][j] == 'P' || tetris->map[i][j] == 'S')
            tetris->map[i][j] = '0';
    start.y = start.y + 1;
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

void down_tetrimino(tetris_t *tetris)
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