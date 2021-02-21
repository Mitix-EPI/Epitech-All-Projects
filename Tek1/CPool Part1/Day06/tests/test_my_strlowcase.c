/*
** EPITECH PROJECT, 2019
** test_my_sytrlowcase.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, return_value)
{
    char str[31] = {'0'};
    
    strcpy(str, "Ce Programme Marche");
    cr_assert_str_eq(my_strlowcase(str), "ce programme marche");
}
