/*
** EPITECH PROJECT, 2019
** test_cat.c
** File description:
** test function
*/

#include <criterion/criterion.h>

int cat(int argc, char **argv);

int my_putstr(char const *str);

Test(cat, return_cat)
{
    char *argv[2] = {"./cat", "tests/test"};
    int a = 0;

    a = cat(2, argv);
    cr_assert_eq(a, 0);
}

Test(cat, return_cat1)
{
    char *argv[2] = {"./cat", "azertyuiop"};
    int a;

    a = cat(2, argv);
    cr_assert_eq(a, 84);
}

Test(cat, return_cat2)
{
    int a;
    char *argv[2] = {"./cat"};

    a = cat(2, argv);
    cr_assert_eq(a, 0);
}

Test(cat, return_cat3)
{
    int a;
    char *argv[2] = {"./cat", "tests/"};

    a = cat(2, argv);
    cr_assert_eq(a, 84);
}
