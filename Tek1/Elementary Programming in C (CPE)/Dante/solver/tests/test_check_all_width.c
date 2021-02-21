/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_check_all_width
*/

#include <criterion/criterion.h>
#include "solver.h"

int check_all_width(char *buffer, solver_t *solv, int rd);

Test(check_all_width, return0)
{
    solver_t solv;
    cr_assert_eq(check_all_width("ee", &solv, 5), 0);
    cr_assert_eq(check_all_width("*\n**\n", &solv, 5), 0);
}

Test(check_all_width, return1)
{
    solver_t solv;
    cr_assert_eq(check_all_width("\n", &solv, 0), 1);
}