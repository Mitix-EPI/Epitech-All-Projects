/*
** EPITECH PROJECT, 2020
** test my_atoi
** File description:
** unit tests for my_atoi
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_atoi, should_return_positive_number)
{
    int ret = my_atoi("28281efe");

    cr_assert_eq(ret, 28281);
}

Test(my_atoi, should_return_negative_number)
{
    int ret = my_atoi("bla-3789-");

    cr_assert_eq(ret, -3789);
}

Test(my_atoi, should_return_0)
{
    int ret = my_atoi("a\0");
    int ret2 = my_atoi(NULL);

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
}