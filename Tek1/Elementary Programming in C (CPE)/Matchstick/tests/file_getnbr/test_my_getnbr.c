/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_my_getnbr
*/

#include <criterion/criterion.h>

int my_getnbr(char const *str);

Test(my_getnbr, should_return_42)
{
    char *str = "42";
    int nb = 0;

    nb = my_getnbr(str);
    cr_assert_eq(nb, 42);
}

Test(my_getnbr, should_return_84)
{
    char *str = " ";
    int nb = 0;

    nb = my_getnbr(str);
    cr_assert_eq(nb, -84);
    nb = my_getnbr("a");
    cr_assert_eq(nb, -84);
    nb = my_getnbr("6 ");
    cr_assert_eq(nb, -84);
}
