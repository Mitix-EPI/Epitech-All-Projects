/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_if_condition
*/

#include <criterion/criterion.h>
#include "generator.h"

int if_condition(char **map, int i, int j);

Test(if_condition, return_0)
{
    char **map = malloc(sizeof(char *) * (5 + 1));
    for (int i = 0; i < 3; i++)
        map[i] = malloc(sizeof(char) * 5);
    cr_assert_eq(if_condition(map, 0, 0), 0);
    cr_assert_eq(if_condition(map, 2, 2), 0);
    cr_assert_eq(if_condition(map, 1, 0), 0);
    cr_assert_eq(if_condition(map, 2, 1), 0);
    cr_assert_eq(if_condition(map, 1, 1), 0);
    for (int i = 0; i < 3; i++)
        free(map[i]);
    free(map);
}