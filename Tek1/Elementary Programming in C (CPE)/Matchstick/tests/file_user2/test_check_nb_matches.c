/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(check_nb_matches, return_3)
{
    matchstick_t ms;
    char *array[3] = {"*   *\n", "*|||*\n", NULL};

    ms.board = array;
    cr_assert_eq(check_nb_matches(&ms, 1), 3);
}