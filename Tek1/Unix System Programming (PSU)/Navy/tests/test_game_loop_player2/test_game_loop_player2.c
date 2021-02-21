/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_game_loop_player2
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(build_coord, return_str)
{
    char *rep = build_coord('A', '1');
    cr_assert_str_eq(rep, "A1");
    free(rep);
}