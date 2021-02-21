/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** test_my_str
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(my_str, should_return_first_str)
{
    char *ret = my_str("yolo-habibi");

    cr_assert_str_eq(ret, "yolo");
    free(ret);
}

Test(my_str, should_return_NULL)
{
    char *res = NULL;
    char *ret = my_str(res);

    cr_assert_null(ret);
}

Test(my_str, should_return_first_str_part2)
{
    char *ret = my_str("cyriL + paul + juan = <3");
    char *ret2 = my_str("AyPiL6+ paul + juan = <3");
    char *ret3 = my_str("AyPil");
    char *ret4 = my_str("azyPil");

    cr_assert_str_eq(ret, "cyriL");
    cr_assert_str_eq(ret2, "AyPiL6");
    cr_assert_str_eq(ret3, "AyPil");
    cr_assert_str_eq(ret4, "azyPil");
    free(ret);
    free(ret2);
    free(ret3);
    free(ret4);
}