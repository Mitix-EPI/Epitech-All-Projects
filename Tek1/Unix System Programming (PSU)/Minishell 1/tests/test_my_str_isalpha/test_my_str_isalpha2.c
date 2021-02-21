/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_str_isalpha2
*/

#include <criterion/criterion.h>
#include "../../include/my.h"

Test(my_str_isalpha2, return_0)
{
    cr_assert_eq(my_str_isalpha2("@"), 0);
    cr_assert_eq(my_str_isalpha2("["), 0);
    cr_assert_eq(my_str_isalpha2("{"), 0);
}

Test(my_str_isalpha2, return_1)
{
    cr_assert_eq(my_str_isalpha2("yolo"), 1);
}