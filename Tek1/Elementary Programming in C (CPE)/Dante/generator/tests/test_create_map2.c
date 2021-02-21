/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_create_map2
*/

#include "generator.h"
#include <criterion/criterion.h>

Test(create_map2, return_map)
{
    char **map = create_map2(1, 1);
    cr_assert_str_eq(map[0], "*");
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}