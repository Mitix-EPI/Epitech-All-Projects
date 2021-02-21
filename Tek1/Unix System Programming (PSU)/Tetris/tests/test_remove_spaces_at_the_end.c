/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_remove_spaces_at_the_end
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test(remove_spaces_at_the_end, return_good_str)
{
    cr_assert_str_eq(remove_spaces_at_the_end("Salut "), "Salut");
}

Test(remove_spaces_at_the_end, return_good_str_with_more_spaces)
{
    cr_assert_str_eq(remove_spaces_at_the_end("Salut       "), "Salut");
}