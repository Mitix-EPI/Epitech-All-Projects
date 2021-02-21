/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_issafe
*/

#include <criterion/criterion.h>
#include "solver.h"

int issafe(char *mapa, int x, int y, int *x_max);

Test(issafe, return0)
{
    int x_max[2] = {0, 0};
    cr_assert_eq(issafe("***", 0, 0, x_max), 0);
}

Test(issafe, return1)
{
    int x_max[2] = {3, 3};
    cr_assert_eq(issafe("***", 0, 0, x_max), 1);
}