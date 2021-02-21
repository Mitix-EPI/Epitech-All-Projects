/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(check_existing_line, return0)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    cr_assert_eq(check_existing_line(&ms, 1), 0);
}

Test(check_existing_line, return1)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    ms.board = array;
    cr_assert_eq(check_existing_line(&ms, 2), 1);
}