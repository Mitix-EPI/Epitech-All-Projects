/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_char_isnum(char c);

Test(my_char_isnum, should_return_0)
{
    cr_assert_eq(my_char_isnum('0'), 0);
}

Test(my_char_isnum, should_return_1)
{
    cr_assert_eq(my_char_isnum('a'), 1);
}