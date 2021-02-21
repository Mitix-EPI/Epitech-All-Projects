/*
** EPITECH PROJECT, 2020
** test my_putstr
** File description:
** units tests for my_putstr function
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_putchar, should_display_char_stdout)
{
    cr_redirect_stdout();
    my_putchar(1, 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putstr, should_display_str_stdout)
{
    cr_redirect_stdout();
    my_putstr(1, "Coucou\n");
    cr_assert_stdout_eq_str("Coucou\n");
}

Test(my_putstr, should_display_nothing)
{
    cr_redirect_stdout();
    my_putstr(1, NULL);
    cr_assert_stdout_neq_str("");
}