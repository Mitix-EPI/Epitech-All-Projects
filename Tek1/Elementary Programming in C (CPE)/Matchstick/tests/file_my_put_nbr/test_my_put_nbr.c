/*
** EPITECH PROJECT, 2019
** criterion test
** File description:
** test revstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

int my_put_nbr(int nb);

void redirect(void)
{
    cr_redirect_stdout();
}

Test(my_put_nbr, nbr_is_print, .init = redirect)
{
    int i = 53423;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("53423", "53423");
}

Test(my_put_nbr, nbr_is_print2, .init = redirect)
{
    int i = 0;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("0", "0");
}

Test(my_put_nbr, nbr_is_print3, .init = redirect)
{
    int i = -123456;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("-123456", "-123456");
}