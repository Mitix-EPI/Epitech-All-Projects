/*
** EPITECH PROJECT, 2019
** test_str_islower.c
** File description:
** return value
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, return_value)
{
    char str[14] = {'0'};

    strcpy(str, "vousetesbelle");
    cr_assert_eq(my_str_islower(str), 1);
}
