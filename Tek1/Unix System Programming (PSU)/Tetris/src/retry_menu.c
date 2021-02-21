/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** retry_menu
*/

#include "../include/my.h"

int retry_menu(tetris_t *tetris)
{
    nodelay(stdscr, false);
    curs_set(1);
    for (int retry = 0; 1;) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - (my_strlen("RETRY ? : Y/N") /
        2), "RETRY ? : Y/N");
        retry = getch();
        if (retry == 'y') {
            tetris->loose = 0;
            break;
        }
        else if (retry == 'n')
            break;
        refresh();
    }
    curs_set(0);
    nodelay(stdscr, true);
    return (0);
}