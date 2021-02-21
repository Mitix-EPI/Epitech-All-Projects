/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(end_retur_n, return_0)
{
    char *str1 = malloc(sizeof(char) * 1);
    char *str2 = malloc(sizeof(char) * 1);
    char **array = NULL;

    cr_assert_eq(end_retur_n(str1, str2, array, 0), 0);
}

Test(end_retur_n, return_1)
{
    char *str1 = malloc(sizeof(char) * 1);
    char *str2 = malloc(sizeof(char) * 1);
    char **array = malloc(sizeof(char) * 2);

    array[0] = malloc(sizeof(char) * 1);
    array[1] = NULL;
    cr_assert_eq(end_retur_n(str1, str2, array, 1), 1);
}