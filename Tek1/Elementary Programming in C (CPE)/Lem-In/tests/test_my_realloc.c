/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** test_my_realloc
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_realloc, return_exactly_same_str)
{
    char *txt = malloc(sizeof(char) * (3 + 1));
    char *ret = NULL;

    txt[0] = 's';
    txt[1] = 'l';
    txt[2] = 't';
    txt[3] = 0;
    ret = my_realloc(txt, my_strlen(txt));
    cr_assert_str_eq(ret, "slt");
    free(ret);
}