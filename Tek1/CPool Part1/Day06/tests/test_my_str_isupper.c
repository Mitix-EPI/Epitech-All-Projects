/*
** EPITECH PROJECT, 2019
** test_my_str_isupper.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, return_value)
{
    char str[12] = {'0'};

    strcpy(str, "AZERTYUIOpQ");
    cr_assert_eq(my_str_isupper(str), 0);
}
