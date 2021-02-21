/*
** EPITECH PROJECT, 2020
** test empty_line
** File description:
** unit tests for the function empty_line
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(check_empty_line, should_return_1)
{
    char txt[] = "        ";
    char txt2[] = "\t\t     \t";
    int ret = check_empty_line(txt);
    int ret2 = check_empty_line(txt2);

    cr_assert_eq(ret, 1);
    cr_assert_eq(ret2, 1);
}

Test(check_empty_line, should_return_0)
{
    char txt[] = "Salut";
    char txt2[] = "\t    Salut\t \t    ";
    int ret = check_empty_line(txt);
    int ret2 = check_empty_line(txt2);

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
}