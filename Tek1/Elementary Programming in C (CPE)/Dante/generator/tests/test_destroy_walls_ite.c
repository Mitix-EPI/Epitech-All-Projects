/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_destroy_walls_ite
*/

#include "generator.h"
#include <criterion/criterion.h>

void destroy_walls_ite(vector_t up_left, char **map, int i, int j);

Test(destroy_walls_ite, change_map_values)
{
    char **map = create_map2(2, 2);
    vector_t up_left = {0, 0};

    up_left.x = 1;
    destroy_walls_ite(up_left, map, 1, 1);
    cr_assert_eq(map[1][0], '*');
    up_left.x = 0;
    up_left.y = 1;
    destroy_walls_ite(up_left, map, 1, 1);
    cr_assert_eq(map[0][1], '*');
    up_left.x = 1;
    destroy_walls_ite(up_left, map, 1, 1);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
