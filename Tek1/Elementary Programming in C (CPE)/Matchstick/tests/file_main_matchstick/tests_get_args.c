/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(get_args, return_0)
{
    matchstick_t ms;
    char *array[5] = {"*****\n" , "*   *\n", "*   *\n", "*****\n", NULL};

    cr_assert_eq(get_args(0, array, &ms), 0);
}

Test(get_args, return_1)
{
    matchstick_t ms;
    char *array[4] = {"./", "1", "101", NULL};
    char *array2[4] = {"./", "101", "1", NULL};
    char *array3[4] = {"./", "2", "0", NULL};

    cr_assert_eq(get_args(3, array, &ms), 1);
    cr_assert_eq(get_args(3, array2, &ms), 1);
    cr_assert_eq(get_args(3, array3, &ms), 1);
}