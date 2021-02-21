/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_my_getnbr
*/

#include <criterion/criterion.h>

int my_getnbr(char const *str);

Test(my_getnbr, should_return_42)
{
    char *str = "42jemepresentejemappellehenry42gentillepersonne";
    int nb = 0;

    nb = my_getnbr(str);
    cr_assert_eq(nb, 42);
}

Test(my_getnbr, should_return_neg42)
{
    char *str = "-42";
    int nb = 0;

    nb = my_getnbr(str);
    cr_assert_eq(nb, -42);
}

Test(my_getnbr, should_return_0)
{
    char *str = "76543234567854";
    int nb = 0;

    cr_assert_eq(nb, 0);
}
