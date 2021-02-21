/*
** EPITECH PROJECT, 2020
** test my_putnbr
** File description:
** unit tests for my_put_nbr
*/

#include "lemin.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_putnbr, should_display_positive_number)
{
    cr_redirect_stdout();
    my_putnbr(231);
    cr_assert_stdout_eq_str("231");
}

Test(my_putnbr, should_display_bigger_number)
{
    cr_redirect_stdout();
    my_putnbr(-2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_putnbr, should_display_negative_number)
{
    cr_redirect_stdout();
    my_putnbr(-371);
    cr_assert_stdout_eq_str("-371");
}