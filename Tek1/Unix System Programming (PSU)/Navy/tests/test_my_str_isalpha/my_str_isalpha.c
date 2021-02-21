/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_str_isalpha
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_str_isalpha(char const *str);

int my_char_isalpha(char c);

Test(my_str_isalpha, should_return_1)
{
    cr_assert_eq(my_str_isalpha("123"), 1);
}

Test(my_str_isalpha, should_return_0)
{
    cr_assert_eq(my_str_isalpha("ABC"), 0);
}

Test(my_char_isalpha, should_return_1)
{
    cr_assert_eq(my_char_isalpha('A'), 1);
}

Test(my_char_isalpha, should_return_0)
{
    cr_assert_eq(my_char_isalpha('1'), 0);
}