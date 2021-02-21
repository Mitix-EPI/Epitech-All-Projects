/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** user_rules
*/

#include "../include/my.h"

static struct option long_options[] = {
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 0},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {0, 0, 0, 0}
};

int key_bind(int opt, tetris_t *tetris)
{
    if (opt == 'l') {
        tetris->LEFT = optarg;
        return (0);
    }
    if (opt == 'r') {
        tetris->RIGHT = optarg;
        return (0);
    }
    if (opt == 't' || opt == 'd')
        return (key_bind_two(opt, tetris));
    return (0);
}

int second_key_bind(int opt, tetris_t *tetris)
{
    if (opt == 'q') {
        tetris->QUIT = optarg;
        return (0);
    }
    if (opt == 'p') {
        tetris->PAUSE = optarg;
        return (0);
    }
    if (opt == 'w') {
        tetris->hide_next = 1;
        return (0);
    }
    if (opt == 'D') {
        tetris->debug = 1;
        return (0);
    }
    return (0);
}

int if_forest(int opt, tetris_t *tetris)
{
    if (opt == 'L') {
        if (optarg[0] < 48 || optarg[0] > 57) {
            return (84);
        }
        tetris->level = my_getnbr(optarg);
        return (0);
    }
    if (opt == 'l' || opt == 'r' || opt == 't' || opt == 'd')
        return (key_bind(opt, tetris));
    if (opt == 'q' || opt == 'p' || opt == 'w' || opt == 'D')
        return (second_key_bind(opt, tetris));
    if (opt == 0) {
        if (optarg[0] < 48 || optarg[0] > 57) {
            return (84);
        }
        if (get_row_and_col(tetris, optarg) == 84)
            return (84);
        return (0);
    } else {
        return (84);
    }
}

int set_user_rules(int ac, char **av, tetris_t *tetris)
{
    int opt = 0;
    tetris->change = 0;
    for (int option_index = 0; 1; option_index = 0) {
        opt = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", long_options\
        , &option_index);
        if (opt == -1)
            break;
        if (if_forest(opt, tetris) == 84)
            return (84);
    }
    return (0);
}
