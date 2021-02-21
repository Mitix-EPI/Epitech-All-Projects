/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_end_solve
*/

#include "solver.h"
#include <criterion/criterion.h>

Test(end_solver, return_1)
{
    char *str = malloc(sizeof(char) * 2);
    cr_assert_eq(end_solver(str, 0), 1);
    free(str);
}