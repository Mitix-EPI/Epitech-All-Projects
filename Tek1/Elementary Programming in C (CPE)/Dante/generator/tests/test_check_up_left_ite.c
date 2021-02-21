/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_check_up_left_ite
*/

#include "generator.h"
#include <criterion/criterion.h>

void check_up_left_ite(char **map, int i, int j, vector_t *up_rigth);

Test(check_up_left_ite, give_good_values)
{
    char **map = create_map2(3, 3);
    vector_t up_right;

    map[1][2] = 'X';
    map[2][1] = 'X';
    check_up_left_ite(map, 2, 2, &up_right);
    cr_assert_eq(up_right.x, 1);
    cr_assert_eq(up_right.y, 1);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}