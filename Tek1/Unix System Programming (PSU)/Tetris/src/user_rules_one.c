/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** user_rules_one
*/

#include "../include/my.h"

int key_bind_two(int opt, tetris_t *tetris)
{
    if (opt == 't') {
        tetris->TURN = optarg;
        return (0);
    }
    if (opt == 'd') {
        tetris->DOWN = optarg;
        return (0);
    }
    return (0);
}