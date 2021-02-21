/*
** EPITECH PROJECT, 2019
** test_my_strncat.c
** File description:
** return value
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strncat(char *dest, char const *src, int nb);

Test(my_strncat, return_value)
{
    char src[12] = {'0'};
    char dest[12] = {'0'};
    int nb = 5;

    strcpy(src, "Jubilatoire");
    strcpy(dest, "Ceci est : ");
    cr_assert_str_eq(my_strncat(dest, src, nb), strncat(dest, src, nb));
}
