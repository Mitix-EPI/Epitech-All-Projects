/*
** EPITECH PROJECT, 2020
** test get_nb_digit
** File description:
** unit tests for get_nb_digit
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(get_nb_digit, should_return_3e)
{
    int ret = get_nb_digit(186);

    cr_assert_eq(ret, 3);
}