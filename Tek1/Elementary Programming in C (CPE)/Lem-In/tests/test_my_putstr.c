/*
** EPITECH PROJECT, 2020
** test my_putstr
** File description:
** unit tests for my_putstr
*/

#include "lemin.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_putstr, should_display_message)
{
    int ret = 0;

    cr_redirect_stdout();
    ret = my_putstr(1, "Hi how are you ?");
    cr_assert_stdout_eq_str("Hi how are you ?");
    cr_assert_eq(ret, 0);
}

Test(my_putstr, should_display_error_message)
{
    int ret = 0;

    cr_redirect_stderr();
    ret = my_putstr(2, "This is an error message.");
    cr_assert_stderr_eq_str("This is an error message.");
    cr_assert_eq(ret, 84);
}