/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_dot_tetrimino
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test(dot_tetrimino, return_0)
{
    cr_assert_eq(dot_tetrimino("blabla"), 0);
    cr_assert_eq(dot_tetrimino("blabla.tetriminos"), 0);
}

Test(dot_tetrimino, return_1)
{
    cr_assert_eq(dot_tetrimino(".tetrimino"), 1);
    cr_assert_eq(dot_tetrimino("blabla.tetrimino"), 1);
}