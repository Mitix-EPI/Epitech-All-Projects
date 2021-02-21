/*
** EPITECH PROJECT, 2019
** test_my_str_isnum.c
** File description:
** test function
*/

#include <criterion/criterion.h>
#include <string.h>

int my_str_isnum(char const *str);

Test(my_str_isnum, return_value)
{
    char str[9] = {'0'};

    strcpy(str, "7348vj65");
    cr_assert_eq(my_str_isnum(str), 0);
}
