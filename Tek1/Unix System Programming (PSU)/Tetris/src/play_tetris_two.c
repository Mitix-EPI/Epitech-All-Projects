/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** play_tetris_two
*/

#include "../include/my.h"

void display_c_board(WINDOW *c, tetris_t *tetris)
{
    int id = tetris->id_next;
    for (int i = 1; tetris->tetrimino[id].origin[i] != NULL; i++)
        mvwprintw(c, i , 1, "%s", tetris->tetrimino[id].origin[i]);
}

void display_boards(tetris_t *tetris, WINDOW *a, WINDOW *b, WINDOW *c)
{
    wborder(a, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(b, '|', '|', '-', '-', '/', 92, 92, '/');
    if (tetris->hide_next == 0) {
        wborder(c, '|', '|', '-', '-', '/', 92, 92, '/');
        mvwprintw(c, 0, 2, "next");
        if (tetris->id_next >= 0) {
            display_c_board(c, tetris);
        }
    }
    mvwprintw(b, 2, 2, "High Score");
    mvwprintw(b, 3, 2, "Score %d", tetris->score);
    mvwprintw(b, 5, 2, "Lines %d", tetris->lines);
    mvwprintw(b, 6, 2, "Level %d", tetris->level);
    mvwprintw(b, 8, 2, "Timer %d", (int) tetris->time);
}

void display_tetriminos(tetris_t *tetris, WINDOW *a)
{
    for (int i = 0; tetris->map[i] != NULL; i++) {
        for (int j = 0; tetris->map[i][j]; j++) {
            if (tetris->map[i][j] != '0')
                mvwprintw(a, i + 1, j + 1, "%c", tetris->map[i][j]);
            if (tetris->map[i][j] == 'P')
                mvwprintw(a, i + 1, j + 1, "*");
            if (tetris->map[i][j] == 'S')
                mvwprintw(a, i + 1, j + 1, " ");
        }
    }
}

vector_t return_y_x_max(char **map)
{
    vector_t size;
    int x = 0;
    int y = 0;

    for (y = 0; map[y] != NULL; y++) {
        for (int i = 0; map[y][i]; i++)
            if (i > x)
                x = i;
    }
    size.y = y;
    size.x = x;
    return (size);
}

void clear_player(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j]; j++)
            if (map[i][j] == 'P' || map[i][j] == 'S')
                map[i][j] = '0';
    }
}