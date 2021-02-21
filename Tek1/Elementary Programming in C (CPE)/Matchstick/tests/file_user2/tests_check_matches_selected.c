/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(check_matches_selected, return_0)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    ms.line = 3;
    ms.max_matches = 5;
    cr_assert_eq(check_matches_selected(&ms, -84, 0), 0);
    cr_assert_eq(check_matches_selected(&ms, -1, 0), 0);
    cr_assert_eq(check_matches_selected(&ms, 0, 0), 0);
    cr_assert_eq(check_matches_selected(&ms, 7, 0), 0);
    cr_assert_eq(check_matches_selected(&ms, 2, 1), 0);
}

Test(check_matches_selected, return_1)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    ms.line = 3;
    ms.max_matches = 5;
    cr_assert_eq(check_matches_selected(&ms, 2, 2), 1);
}