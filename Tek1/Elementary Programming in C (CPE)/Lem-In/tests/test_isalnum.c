/*
** EPITECH PROJECT, 2020
** test isalnum
** File description:
** unit tests for isalnum
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_isalnum, should_return_1)
{
    int ret = my_isalnum('8');

    cr_assert_eq(ret, 1);
}

Test(my_isalnum, should_return_0)
{
    int ret = my_isalnum('c');

    cr_assert_eq(ret, 0);
}