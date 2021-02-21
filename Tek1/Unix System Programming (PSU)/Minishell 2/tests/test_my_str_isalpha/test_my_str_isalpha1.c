/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_str_isalpha1
*/

#include <criterion/criterion.h>
#include "../../include/my.h"

Test(my_str_isalpha1, return_0)
{
    cr_assert_eq(my_str_isalpha1("!"), 0);
    cr_assert_eq(my_str_isalpha1("@"), 0);
    cr_assert_eq(my_str_isalpha1("["), 0);
    cr_assert_eq(my_str_isalpha1("{"), 0);
}

Test(my_str_isalpha1, return_1)
{
    cr_assert_eq(my_str_isalpha1("a"), 1);
    cr_assert_eq(my_str_isalpha1("="), 1);
    cr_assert_eq(my_str_isalpha1("_"), 1);
}