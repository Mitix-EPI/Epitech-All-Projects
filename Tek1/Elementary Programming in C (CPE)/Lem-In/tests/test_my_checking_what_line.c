/*
** EPITECH PROJECT, 2020
** test my_checking_what_line
** File description:
** unit tests for my_checking_what_line
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(what_line, should_return_1)
{
    int ret = what_line("3-8");
    int ret2 = what_line("3-1 # Hi");

    cr_assert_eq(ret, 1);
    cr_assert_eq(ret2, 1);
}

Test(what_line, should_return_0)
{
    int ret = what_line("3 8 9");
    int ret2 = what_line("3 8 9 # Coucou");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret, 0);
}

Test(what_line, should_return_negative)
{
    int ret = what_line("3-8-7");

    cr_assert_eq(ret, -1);
}