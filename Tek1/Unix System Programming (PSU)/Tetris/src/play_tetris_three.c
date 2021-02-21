/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** play_tetris_three
*/

#include "../include/my.h"

void remplace_into_map(char **map, char **tetri, vector_t old)
{
    int x = 0;

    for (int i = 0; map[old.y] && tetri[i] != NULL; old.y++, i++) {
        for (int j = 0, x = old.x; map[old.y][x] && tetri[i][j]; x++, j++) {
            if (tetri[i][j] == '*')
                map[old.y][x] = 'P';
            if (tetri[i][j] == ' ')
                map[old.y][x] = 'S';
        }
    }
}

void turn_tetrimino(tetris_t *tetris)
{
    return;
}

int controls(tetris_t *tetris, char b)
{
    if (tetris->tetrimino_selected == 1) {
        if (b == tetris->key_left) {
            move_left(tetris);
            return (1);
        } if (b == tetris->key_right) {
            move_right(tetris);
            return (1);
        } if (b == tetris->key_down) {
            move_down(tetris);
            return (1);
        }
        if (b == tetris->key_turn) {
            turn_tetrimino(tetris);
            return (1);
        }
    }
    return (0);
}

void display(tetris_t *tetris, WINDOW *a, WINDOW *b, WINDOW *c)
{
    display_tetris_name();
    display_boards(tetris, a, b, c);
    display_tetriminos(tetris, a);
}

int bind_touch(tetris_t *tetris, WINDOW *a, clock_t *clockk)
{
    int b = getch();

    if (b == tetris->key_quit) {
        tetris->quit = 1;
        return (0);
    }
    if (b == tetris->key_pause) {
        if (tetris->activated_pause == 0)
            tetris->activated_pause = 1;
        else if (tetris->activated_pause == 1)
            tetris->activated_pause = 0;
        return (1);
    }
    if (controls(tetris, b))
        return (1);
    gameplay(tetris, a, clockk);
    loose(tetris);
    return (1);
}