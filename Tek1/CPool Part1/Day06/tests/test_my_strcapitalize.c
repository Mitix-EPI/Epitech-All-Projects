/*
** EPITECH PROJECT, 2019
** test_my_strcapitalize.c
** File description:
** test function capitalize
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, return_value)
{
    char str[47] = {'0'};

    strcpy(str, "hey, how are you?");
    cr_assert_str_eq(my_strcapitalize(str), "Hey, How Are You?");
}
