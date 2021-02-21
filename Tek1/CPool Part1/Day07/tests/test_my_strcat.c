/*
** EPITECH PROJECT, 2019
** test_my_strcat.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strcat(char *dest, char const *src);

Test(my_strcat, return_value)
{
    char str[14] = {'0'};
    char dest[13] = {'0'};

    strcpy(str, " j'4aime bien");
    strcpy(dest, "Vous aimez ?");
    cr_assert_str_eq(my_strcat(dest, str), strcat(dest, str));
}
