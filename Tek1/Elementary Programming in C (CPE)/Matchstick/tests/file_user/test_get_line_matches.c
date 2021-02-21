/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_get_line_matches
*/

#include "../../include/my.h"
#include <criterion/criterion.h>

Test(get_line_matches, return_0)
{
    matchstick_t ms;
    ms.max_matches = 0;

    cr_assert_eq(get_line_matches(&ms), 0);
}