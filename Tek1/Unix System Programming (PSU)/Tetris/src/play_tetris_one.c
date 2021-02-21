/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** play_tetris_one
*/

#include "../include/my.h"

char *good_tetriminos(tetris_t *tetris)
{
    int x = 0;
    char *res = malloc(sizeof(char) * (tetris->nb_tetriminos + 1));
    res[tetris->nb_tetriminos] = 0;
    for (int i = 0; i < tetris->nb_tetriminos; i++)
        if (tetris->tetrimino[i].type != NULL) {
            res[x] = i + '0';
            x += 1;
        }
    res[x] = 0;
    return (res);
}

void bind_keys(char *str, int *key)
{
    if (str[0] == '^') {
        *key = str[3];
        return;
    }
    if (str[0] == '(') {
        *key = 32;
        return;
    }
    *key = str[0];
}

void fix_keys(tetris_t *tetris)
{
    bind_keys(tetris->LEFT, &tetris->key_left);
    bind_keys(tetris->RIGHT, &tetris->key_right);
    bind_keys(tetris->DOWN, &tetris->key_down);
    bind_keys(tetris->TURN, &tetris->key_turn);
    bind_keys(tetris->QUIT, &tetris->key_quit);
    bind_keys(tetris->PAUSE, &tetris->key_pause);
}

void initialisation(tetris_t *tetris)
{
    WINDOW *boite;
    WINDOW *boite2;
    WINDOW *boite3;
    int b = 0;
    tetris->lines = 0;
    tetris->score = 0;
    tetris->time = 0;
    tetris->tetrimino_selected = 0;
    tetris->activated_pause = 0;
    tetris->map = create_map(tetris);
    tetris->good_tetr = good_tetriminos(tetris);
    tetris->id_next = -1;
    tetris->quit = 0;
    fix_keys(tetris);
    initscr();
    nodelay(stdscr, true);
    curs_set(0);
    start_color();
    init_colorpairs();
}

void display_error(void)
{
    while (COLS < 67 || LINES < 21) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - (my_strlen("TEST") / 2), "ERROR");
        refresh();
    }
}