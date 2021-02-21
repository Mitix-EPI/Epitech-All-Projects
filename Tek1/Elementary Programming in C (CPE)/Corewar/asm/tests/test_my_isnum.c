/*
** EPITECH PROJECT, 2020
** test my_isnum
** File description:
** units tests for functions in my_isnum
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(my_isnum, should_return_1)
{
    char str[] = "3781";
    char str1[] = "0";
    char str2[] = "9999999";
    int ret = my_isnum(str);
    int ret1 = my_isnum(str1);
    int ret2 = my_isnum(str2);

    cr_assert_eq(ret, 1);
    cr_assert_eq(ret1, 1);
    cr_assert_eq(ret2, 1);
}