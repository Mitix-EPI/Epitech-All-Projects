/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_check_file
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_file, return0)
{
    char **map = malloc(sizeof(char *) * (4 + 1));
    map[0] = "2:C1:C2";
    map[1] = "3:D4:F4";
    map[2] = "4:B5:B8";
    map[3] = "5:D7:H7";
    map[4] = NULL;
    cr_assert_eq(check_file(map), 0);
    free(map);
}

Test(check_file, return1_1)
{
    char **map = malloc(sizeof(char *) * (4 + 1));
    map[0] = "2:C1:C";
    map[1] = "3:D4:F4";
    map[2] = "4:B5:B8";
    map[3] = "5:D7:H7";
    map[4] = NULL;
    cr_assert_eq(check_file(map), 1);
    free(map);
}

Test(check_file, return1_2)
{
    char **map = malloc(sizeof(char *) * (4 + 1));
    map[0] = "2:11:C2";
    map[1] = "3:D4:F4";
    map[2] = "4:B5:B8";
    map[3] = "5:D7:H7";
    map[4] = NULL;
    cr_assert_eq(check_file(map), 1);
    map[0] = "2:C1:12";
    cr_assert_eq(check_file(map), 1);
    map[0] = "A:C1:C2";
    cr_assert_eq(check_file(map), 1);
    map[0] = "2:CA:C2";
    cr_assert_eq(check_file(map), 1);
    map[0] = "2:C1:CA";
    cr_assert_eq(check_file(map), 1);
    map[0] = "2AC1:C2";
    cr_assert_eq(check_file(map), 1);
    map[0] = "2:C1AC2";
    cr_assert_eq(check_file(map), 1);
    free(map);
}