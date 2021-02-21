/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** test_my_ls
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_ls, return0)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "-lt";
    av[2] = NULL;

    cr_assert_eq(my_ls(2, av), 0);
}

Test(my_ls, return0_1)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "-d";
    av[2] = NULL;

    cr_assert_eq(my_ls(2, av), 0);
}

Test(my_ls, return0_2)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = NULL;
    av[2] = NULL;

    cr_assert_eq(my_ls(1, av), 0);
}

Test(my_ls, return0_3)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "hfioe";
    av[2] = NULL;

    cr_assert_eq(my_ls(2, av), 84);
}

Test(my_ls, return0_4)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "src";
    av[2] = NULL;

    cr_assert_eq(my_ls(2, av), 0);
}

Test(my_ls, return0_5)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "src";
    av[2] = "-lt";
    av[3] = NULL;

    cr_assert_eq(my_ls(3, av), 0);
}

Test(my_ls, return0_6)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "src";
    av[2] = "-d";
    av[3] = NULL;

    cr_assert_eq(my_ls(3, av), 0);
}

Test(my_ls, return0_7)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "src";
    av[2] = "-l";
    av[3] = NULL;

    cr_assert_eq(my_ls(3, av), 0);
}

Test(my_ls, return0_8)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "src";
    av[2] = "-t";
    av[3] = NULL;

    cr_assert_eq(my_ls(3, av), 0);
}

Test(my_ls, return0_9)
{
    char **av;
    av[0] = "./my_ls";
    av[1] = "src";
    av[2] = NULL;

    cr_assert_eq(my_ls(2, av), 0);
}