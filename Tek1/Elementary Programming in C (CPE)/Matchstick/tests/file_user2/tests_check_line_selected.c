/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(check_line_selected, return_0)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    ms.line = 3;
    cr_assert_eq(check_line_selected(&ms, -84), 0);
    cr_assert_eq(check_line_selected(&ms, -1), 0);
    cr_assert_eq(check_line_selected(&ms, 4), 0);
    cr_assert_eq(check_line_selected(&ms, 1), 0);
}

Test(check_line_selected, return_1)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    ms.line = 3;
    cr_assert_eq(check_line_selected(&ms, 2), 1);
}