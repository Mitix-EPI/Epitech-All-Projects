/*
** EPITECH PROJECT, 2020
** test my_strcmp
** File description:
** unit tests for my_strcmp
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_strcmp, should_return_1)
{
    char str[8] = "Bonjour";
    int ret = my_strcmp(str, "Bonjour");

    cr_assert_eq(ret, 1);
}

Test(my_strcmp, should_return_0)
{
    char str[7] = "Bonjou";
    char str2[8] = "BonJour";
    int ret = my_strcmp(str, "Bonjour");
    int ret2 = my_strcmp(str2, "Bonjour");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
}

Test(my_strncmp, should_return_0)
{
    int ret = my_strncmp("Bonjour", "our", 4, 3);

    cr_assert_eq(ret, 0);
}

Test(my_strncmp, should_return_1)
{
    int ret = my_strncmp("Bonjour", "Our", 4, 3);

    cr_assert_eq(ret, 0);
}

Test(my_strncmp, should_return_v2_1)
{
    int ret = my_strncmp("Bonj", "Bonjour", 0, 8);

    cr_assert_eq(ret, 1);
}