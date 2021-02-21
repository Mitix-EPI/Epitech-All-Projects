/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main_tetris
*/

#include "../include/my.h"

void set_default_rules(tetris_t *tetris)
{
    tetris->level = 1;
    tetris->LEFT = "^EOD";
    tetris->RIGHT = "^EOC";
    tetris->TURN = "^EOA";
    tetris->DOWN = "^EOB";
    tetris->QUIT = "q";
    tetris->PAUSE = "p";
    tetris->row = 20;
    tetris->col = 10;
    tetris->hide_next = 0;
    tetris->debug = 0;
}

int check_same_key(tetris_t *tetris)
{
    if (my_strcmp(tetris->LEFT, tetris->RIGHT) == 0 || my_strcmp(tetris->LEFT,
    tetris->TURN) == 0 || my_strcmp(tetris->LEFT, tetris->DOWN) == 0 ||
    my_strcmp(tetris->LEFT, tetris->QUIT) == 0 ||
    my_strcmp(tetris->LEFT, tetris->PAUSE) == 0)
        return (84);
    if (my_strcmp(tetris->RIGHT, tetris->TURN) == 0 || my_strcmp(tetris->RIGHT,
    tetris->DOWN) == 0 || my_strcmp(tetris->RIGHT, tetris->QUIT) == 0 ||
    my_strcmp(tetris->RIGHT, tetris->PAUSE) == 0)
        return (84);
    if (my_strcmp(tetris->TURN, tetris->DOWN) == 0 || my_strcmp(tetris->TURN,
    tetris->QUIT) == 0 || my_strcmp(tetris->TURN, tetris->PAUSE) == 0)
        return (84);
    if (my_strcmp(tetris->DOWN, tetris->QUIT) == 0 || my_strcmp(tetris->DOWN,
    tetris->PAUSE) == 0)
        return (84);
    if (my_strcmp(tetris->QUIT, tetris->PAUSE) == 0)
        return (84);
    return (0);
}

int tetris(int ac, char **av)
{
    tetris_t tetris;

    set_default_rules(&tetris);
    if (set_user_rules(ac, av, &tetris) == 84) {
        write(2, "Bad Parameter\n", 14);
        display_help(av[0]);
        return (84);
    }
    if (check_same_key(&tetris) == 84)
        return (84);
    if (display_debug_mode(&tetris))
        return (84);
    while (1) {
        play_tetris(&tetris);
        if (tetris.loose == 1 || tetris.quit == 1)
            break;
    }
    all_free(&tetris);
    return (0);
}