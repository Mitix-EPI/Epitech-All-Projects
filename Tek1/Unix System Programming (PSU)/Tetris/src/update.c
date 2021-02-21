/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update
*/

#include "../include/my.h"

void update_timer(tetris_t *tetris, clock_t *clockk)
{
    clockk[1] = clock();
    tetris->time = (((double)(clockk[1] - clockk[0])) / CLOCKS_PER_SEC) * 39;
}

void update_timer_level(tetris_t *tetris)
{
    if (tetris->level == 1)
        tetris->timer_level = 1.4;
    if (tetris->level == 2)
        tetris->timer_level = 1.1;
    if (tetris->level == 3)
        tetris->timer_level = 0.8;
    if (tetris->level == 4)
        tetris->timer_level = 0.7;
    if (tetris->level == 5)
        tetris->timer_level = 0.6;
    if (tetris->level == 6)
        tetris->timer_level = 0.5;
    if (tetris->level == 7)
        tetris->timer_level = 0.4;
    if (tetris->level == 8)
        tetris->timer_level = 0.3;
    if (tetris->level == 9)
        tetris->timer_level = 0.2;
    if (tetris->level == 10)
        tetris->timer_level = 0.1;
}

void update_values(tetris_t *tetris, clock_t *clockk)
{
    update_timer(tetris, clockk);
    update_timer_level(tetris);
}