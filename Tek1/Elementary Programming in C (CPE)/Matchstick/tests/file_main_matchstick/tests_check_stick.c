/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(check_stick, return_0)
{
    char *array[5] = {"*****\n" , "*   *\n", "*   *\n", "*****\n", NULL};

    cr_assert_eq(check_stick(array), 0);
}

Test(check_stick, return_1)
{
    char *array[5] = {"*****\n" , "*   *\n", "*|||*\n", "*****\n", NULL};

    cr_assert_eq(check_stick(array), 1);
}