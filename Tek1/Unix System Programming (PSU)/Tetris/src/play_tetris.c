/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** play_tetris
*/

#include "../include/my.h"

void initialisation_boards(tetris_t *tetri, WINDOW **a, WINDOW **b, WINDOW **c)
{
    *a = subwin(stdscr, tetri->row + 2, tetri->col + 2, 0, 32);
    *b = subwin(stdscr, 10, 27, 8, 0);
    if (tetri->hide_next == 0)
        *c = subwin(stdscr, 8, 22, 0, 32 + 3 + tetri->col + 2);
}

void all_free(tetris_t *tetris)
{
    endwin();
    for (int i = 0; tetris->map[i] != NULL; i++)
        free(tetris->map[i]);
    free(tetris->map);
    free(tetris->good_tetr);
    free(tetris->tetrimino);
}

clock_t *initialise_clocks(void)
{
    clock_t *clockk = malloc(sizeof(clockk) * 4);
    clockk[0] = clock();
    clockk[2] = clock();
    return (clockk);
}

int play_tetris(tetris_t *tetris)
{
    WINDOW *boite;
    WINDOW *boite2;
    WINDOW *boite3;
    clock_t *clockk = initialise_clocks();
    initialisation(tetris);
    initialisation_boards(tetris, &boite, &boite2, &boite3);
    for (; tetris->loose != 1;) {
        clear();
        noecho();
        update_values(tetris, clockk);
        display(tetris, boite, boite2, boite3);
        usleep(25000);
        usleep(25000);
        if (bind_touch(tetris, boite, clockk) == 0)
            break;
        if (tetris->loose == 1) {
            return (retry_menu(tetris));
        }
        refresh();
    }
    return (1);
}