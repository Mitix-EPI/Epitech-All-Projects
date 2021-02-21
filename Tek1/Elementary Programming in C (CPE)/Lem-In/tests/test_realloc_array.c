/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** test_realloc_array
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(realloc_array, return_)
{
    char **tmp = malloc(sizeof(char *) * (1 + 1));
    char **ret = NULL;

    tmp[0] = "hello";
    tmp[1] = NULL;
    ret = realloc_array(tmp, "yolo");
    cr_assert_str_eq(ret[0], "hello");
    cr_assert_str_eq(ret[1], "yolo");
    cr_assert_null(ret[2]);
    for (int i = 0; ret[i] != NULL; i++)
        free(ret[i]);
    free(ret);
    free(tmp);
}