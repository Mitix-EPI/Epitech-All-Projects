/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"

Test(free_board, return_0)
{
    char **array = malloc(sizeof(char) * 2);

    array[0] = malloc(sizeof(char) * 1);
    array[1] = NULL;

    cr_assert_eq(free_board(array), 0);
}