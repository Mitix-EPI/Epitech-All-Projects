/*
** EPITECH PROJECT, 2020
** test my_strlen
** File description:
** unit tests for my_strlen
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_strlen, should_return_0)
{
    int ret = my_strlen(NULL);
    int ret2 = my_strlen("\0");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
}

Test(my_strlen, should_return_number)
{
    int ret = my_strlen("Coucou");

    cr_assert_eq(ret, 6);
}

Test(count_spaces, should_return_number)
{
    int ret = count_spaces("Hi how  are you ?");

    cr_assert_eq(ret, 4);
}

Test(count_spaces, should_return_0)
{
    int ret = count_spaces(NULL);
    int ret2 = count_spaces("\0");
    int ret3 = count_spaces("HiHowAreYou?");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
    cr_assert_eq(ret3, 0);
}