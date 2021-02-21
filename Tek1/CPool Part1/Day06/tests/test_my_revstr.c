/*
** EPITECH PROJECT, 2019
** test_my_revstr.c
** File description:
** test fonction
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, return_value_is_reversed)
{
    char str[6] = {'O'};

    strcpy(str, "Hello");
    cr_assert_str_eq(my_revstr(str), "olleH");
}
