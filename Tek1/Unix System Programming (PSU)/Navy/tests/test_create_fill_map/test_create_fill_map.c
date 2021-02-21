/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_create_fill_map
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(create_fill_map, return_map)
{
    char **map1 = create_fill_map("pos1");
    cr_assert_str_eq(map1[0], " |A B C D E F G H\n");
    for (int i = 0; map1[i] != NULL; i++)
        free(map1[i]);
    free(map1);
}