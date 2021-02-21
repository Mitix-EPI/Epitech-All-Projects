/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_create_map
*/

#include "generator.h"
#include <criterion/criterion.h>

Test(create_map, return_map)
{
    char **map = create_map(1, 1);
    cr_assert_str_eq(map[0], "*");
    for (int i = 0; i < 1; i++)
        free(map[i]);
    free(map);
}