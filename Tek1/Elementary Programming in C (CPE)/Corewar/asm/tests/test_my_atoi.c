/*
** EPITECH PROJECT, 2020
** test my_atoi
** File description:
** units tests for function my_atoi
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(my_atoi, should_return_positive_number)
{
    char str[] = "aa2368";
    char str1[] = "uize90";
    char str2[] = "318sf";
    char str3[] = "rfzefz";
    int ret = my_atoi(str);
    int ret1 = my_atoi(str1);
    int ret2 = my_atoi(str2);
    int ret3 = my_atoi(str3);

    cr_assert_eq(ret, 2368);
    cr_assert_eq(ret1, 90);
    cr_assert_eq(ret2, 318);
    cr_assert_eq(ret3, 0);
}

Test(my_atoi, should_return_negative_numbers)
{
    char str[] = "-389efz";
    char str1[] = "fzofzofz-8320";
    char str2[] = "ezfzeiof-731";
    char *str3 = NULL;
    int ret = my_atoi(str);
    int ret1 = my_atoi(str1);
    int ret2 = my_atoi(str2);
    int ret3 = my_atoi(str3);

    cr_assert_eq(ret, -389);
    cr_assert_eq(ret1, -8320);
    cr_assert_eq(ret2, -731);
    cr_assert_eq(ret3, 0);
}