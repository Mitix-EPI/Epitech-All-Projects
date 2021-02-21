/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_str_isupper
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, should_print_1_into_stdout)
{
    int i = 0;
    cr_redirect_stdout();
    i  = my_str_isupper("");
    cr_assert_eq(i, 1);
}

Test(my_str_isupper, should_print_Hello_into_stdout)
{
    int i = 0;
    cr_redirect_stdout();
    i = my_str_isupper("HELLO");
    cr_assert_eq(i, 1);
}

Test(my_str_isupper, should_print_non_printable_char_into_stdout)
{
    int i = 0;
    cr_redirect_stdout();
    i = my_str_isupper("a");
    cr_assert_eq(i, 0);
}