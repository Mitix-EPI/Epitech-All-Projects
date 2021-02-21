/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move
*/

#include "../include/my.h"

void move_left(sokoban_t *s)
{
    if (s->s_mod[s->y][s->x - 1] == 'X' &&
        s->s_mod[s->y][s->x - 2] != '#' &&
        s->s_mod[s->y][s->x - 2] != 'X' && s->ch == 68) {
        s->s_mod[s->y][s->x - 2] = 'X';
        s->s_mod[s->y][s->x - 1] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    } else if (s->s_mod[s->y][s->x - 1] != '#' &&
        s->s_mod[s->y][s->x - 1] != 'X' && s->ch == 68) {
        s->s_mod[s->y][s->x - 1] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    }
}

void move_up(sokoban_t *s)
{

    if (s->s_mod[s->y - 1][s->x] == 'X' &&
        s->s_mod[s->y - 2][s->x] != '#' &&
        s->s_mod[s->y - 2][s->x] != 'X' && s->ch == 65) {
        s->s_mod[s->y - 2][s->x] = 'X';
        s->s_mod[s->y - 1][s->x] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    } else if (s->s_mod[s->y - 1][s->x] != '#' &&
        s->s_mod[s->y - 1][s->x] != 'X' && s->ch == 65) {
        s->s_mod[s->y - 1][s->x] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    }
}

void move_down(sokoban_t *s)
{
    if (s->s_mod[s->y + 1][s->x] == 'X' &&
        s->s_mod[s->y + 2][s->x] != '#' &&
        s->s_mod[s->y + 2][s->x] != 'X' && s->ch == 66) {
        s->s_mod[s->y + 2][s->x] = 'X';
        s->s_mod[s->y + 1][s->x] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    } else if (s->s_mod[s->y + 1][s->x] != '#' &&
        s->s_mod[s->y + 1][s->x] != 'X' && s->ch == 66) {
        s->s_mod[s->y + 1][s->x] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    }
}

void move_right(sokoban_t *s)
{
    if (s->s_mod[s->y][s->x + 1] == 'X' &&
        s->s_mod[s->y][s->x + 2] != '#' &&
        s->s_mod[s->y][s->x + 2] != 'X' && s->ch == 67) {
        s->s_mod[s->y][s->x + 2] = 'X';
        s->s_mod[s->y][s->x + 1] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    } else if (s->s_mod[s->y][s->x + 1] != '#' &&
        s->s_mod[s->y][s->x + 1] != 'X' && s->ch == 67) {
        s->s_mod[s->y][s->x + 1] = 'P';
        s->s_mod[s->y][s->x] = ' ';
    }
}

int move_player(sokoban_t *s)
{
    if (s->ch == 65)
        move_up(s);
    if (s->ch == 66)
        move_down(s);
    if (s->ch == 67)
        move_right(s);
    if (s->ch == 68)
        move_left(s);
    check_pos_o(s);
    if (check_0(s)) {
            endwin();
            return (1);
    }
    if (find_hashtag(s))
        return (2);
    return (0);
}