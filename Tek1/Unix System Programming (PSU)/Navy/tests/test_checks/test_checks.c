/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_checks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int condition1(char *line, char *char_pos);

int condition2(char *line, char *char_pos);

Test(condition1, return1)
{
    cr_assert_eq(condition1("1:C2:F2", "C2"), 1);
    cr_assert_eq(condition1("1:C2:F2", "C3"), 0);
    cr_assert_eq(condition1("1:C2:F3", "C2"), 0);
}

Test(condition2, return1)
{
    cr_assert_eq(condition2("1:C2:F2", "C2"), 1);
    cr_assert_eq(condition2("1:C2:F2", "C3"), 0);
}