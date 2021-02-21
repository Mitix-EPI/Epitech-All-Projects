/*
** EPITECH PROJECT, 2019
** test_my_str_isprintable.c
** File description:
** return value
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, return_value)
{
    char str[16] = {'0'};

    strcpy(str, "NTM la mouli");
    cr_assert_eq(my_str_isprintable(str), 1);
}
