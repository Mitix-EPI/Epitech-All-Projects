/*
** EPITECH PROJECT, 2019
** test_my_strcpy.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, return_value)
{
    char str[17] = {'0'};
    char dest[21] = {'0'};

    strcpy(str, "je t'écrase fdp");
    strcpy(dest, "non, je fais pas ça");
    cr_assert_eq(my_strcpy(str, dest), strcpy(str, dest));
}
