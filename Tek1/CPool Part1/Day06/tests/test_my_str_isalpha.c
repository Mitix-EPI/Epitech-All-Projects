/*
** EPITECH PROJECT, 2019
** test_my_str_isalpha.c
** File description:
** return value
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, return_value)
{
    char str[19] = {'0'};

    strcpy(str, "EntreChatsEtChiens");
    cr_assert_eq(my_str_isalpha(str), 1);
}
