/*
** EPITECH PROJECT, 2020
** test fills
** File description:
** unit tests for the functions of fills
*/

#include "asm.h"
#include <criterion/criterion.h>

Test(fill_arr_null, should_fill_null_array)
{
    char **array = malloc(sizeof(char *) * (5 + 1));

    fill_arr_null(array, 5);
    cr_assert_null(array[0]);
    cr_assert_null(array[1]);
    cr_assert_null(array[2]);
    cr_assert_null(array[3]);
    cr_assert_null(array[4]);
    cr_assert_null(array[5]);
    free(array);
}

Test(fill_str, should_fill_str_letters)
{
    char *str = malloc(sizeof(char) * (5 + 1));

    str[5] = '\0';
    fill_str(str, 4, 'a');
    cr_assert_str_eq(str, "aaaaa");
    free(str);
}