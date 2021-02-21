/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** gameplay
*/

#include "../include/my.h"

void destroy_line(char **map, tetris_t *tetris)
{
    int res = 0;
    for (int i = 0; map[i] != NULL; i++, res = 0) {
        for (int j = 0; map[i][j]; j++)
            if (map[i][j] != '*')
                res = 1;
        if (res == 0) {
            down_all_lines_above(map, i);
            tetris->score += (40 * tetris->level) + 1;
            tetris->lines += 1;
        }
    }
}

int down_timer(tetris_t *tetris, clock_t *clockk)
{
    double second = 0;

    clockk[3] = clock();
    second = (((double)(clockk[3] - clockk[2])) / CLOCKS_PER_SEC) * 39;
    if (second > tetris->timer_level) {
        clockk[2] = clock();
        if (check_player_touch(tetris))
            return (1);
        down_tetrimino(tetris);
        if (check_player_touch(tetris))
            return (1);
    }
    return (0);
}

void gameplay(tetris_t *tetris, WINDOW *a, clock_t *clockk)
{
    if (tetris->lines == 10)
        tetris->level += 1;
    destroy_line(tetris->map, tetris);
    if (tetris->tetrimino_selected == 1) {
        destroy_line(tetris->map, tetris);
        if (down_timer(tetris, clockk)) {
            destroy_line(tetris->map, tetris);
            return;
        }
    } else {
        select_id_tetrimino(tetris);
        draw_player(tetris, a);
        tetris->tetrimino_selected = 1;
    }
}