/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_checks_other_fcts
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_lenght_boat, return0)
{
    char **map = malloc(sizeof(char *) * (4 + 1));
    map[0] = "2:C1:C2";
    map[1] = "3:D4:F4";
    map[2] = "4:B5:B8";
    map[3] = "5:D7:H7";
    map[4] = NULL;
    cr_assert_eq(check_lenght_boat(map), 0);
}

Test(check_lenght_boat, return1)
{
    char **map = malloc(sizeof(char *) * (4 + 1));
    map[0] = "2:C1:C3";
    map[1] = "3:D4:F4";
    map[2] = "4:B5:B8";
    map[3] = "5:D7:H7";
    map[4] = NULL;
    cr_assert_eq(check_lenght_boat(map), 1);
}

Test(check_lenght_boat, return1a)
{
    char **map = malloc(sizeof(char *) * (4 + 1));
    map[0] = "2:C1:C2";
    map[1] = "3:A4:F4";
    map[2] = "4:B5:B8";
    map[3] = "5:D7:H7";
    map[4] = NULL;
    cr_assert_eq(check_lenght_boat(map), 1);
}