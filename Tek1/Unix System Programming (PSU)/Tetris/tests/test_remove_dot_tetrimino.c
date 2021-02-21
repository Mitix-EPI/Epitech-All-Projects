/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_remove_dot_tetrimino
*/

#include <criterion/criterion.h>
#include "../include/my.h"

char *remove_dot_tetrimino(char *str);

Test(remove_dot_tetrimino, return_AB)
{
    cr_assert_str_eq(remove_dot_tetrimino("AB.tetrimino"), "AB");
}

Test(remove_dot_tetrimino, return_AB_dot_AC)
{
    cr_assert_str_eq(remove_dot_tetrimino("AB.AC.tetrimino"), "AB.AC");
}

Test(remove_dot_tetrimino, return_tetrimino)
{
    cr_assert_str_eq(remove_dot_tetrimino("tetrimino.tetrimino"), "tetrimino");
}