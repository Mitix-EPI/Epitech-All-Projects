/*
** EPITECH PROJECT, 2020
** test my_itoa
** File description:
** unit tests for my_itoa
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_itoa, should_return_str_123)
{
    char *str = malloc(sizeof(char) * 4);
    int x = 123;

    str[0] = 'a';
    my_itoa(str, x);
    cr_assert_str_eq(str, "123");
    free(str);
}

Test(my_itoa, should_return_same_str)
{
    char *str = NULL;

    my_itoa(str, 3);
    cr_assert_null(str);
}

Test(my_itoa, should_return_str_negative)
{
    char *str = malloc(sizeof(char) * 5);
    int x = -123;

    my_itoa(str, x);
    cr_assert_str_eq(str, "-123");
    free(str);
}