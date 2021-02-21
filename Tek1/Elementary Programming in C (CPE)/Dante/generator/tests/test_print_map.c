/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_print_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "generator.h"

Test(print_map, good_output)
{
    char **map = malloc(sizeof(char *) * 2);
    for (int i = 0; i < 2; i++) {
        map[i] = malloc(sizeof(char) * 2);
        map[i][0] = '*';
        map[i][1] = 0;
    }
    cr_redirect_stdout();
    print_map(map, 1, 2);
    cr_assert_stdout_neq_str("*\n*");
    free(map[0]);
    free(map[1]);
    free(map);
}