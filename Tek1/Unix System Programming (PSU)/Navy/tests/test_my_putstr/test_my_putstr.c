/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_putstr
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>

int my_putstr(char const *str);

Test(my_putstr, should_print_ABC_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("ABC");
    cr_assert_stdout_eq_str("ABC");
}

Test(my_putstr, should_print_non_printable_char_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("\a");
    cr_assert_stdout_eq_str("\a");
}

Test(my_putstr, should_print_C_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("C");
    cr_assert_stdout_eq_str("C");
}

Test(my_putstr, should_print_BONJOUR_KARIM_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("BONJOUR KARIM");
    cr_assert_stdout_eq_str("BONJOUR KARIM");
}
