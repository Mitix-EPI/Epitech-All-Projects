/*
** EPITECH PROJECT, 2020
** test my_putnbr
** File description:
** unit tests to put the nbr
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_put_nbr, should_display_positive_number)
{
    cr_redirect_stdout();
    my_put_nbr(739);
    cr_assert_stdout_eq_str("739");
}

Test(my_put_nbr, should_display_negative_number)
{
    cr_redirect_stdout();
    my_put_nbr(-3719);
    cr_assert_stdout_eq_str("3719-");
}