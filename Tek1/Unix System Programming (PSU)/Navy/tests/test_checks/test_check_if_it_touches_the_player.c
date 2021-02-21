/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_check_if_it_touches_the_player
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_if_it_touches_the_player, return0)
{
    data.pos_map = malloc(sizeof(char *) * (4 + 1));
    data.pos_map[0] = "2:C1:C2";
    data.pos_map[1] = "3:D4:F4";
    data.pos_map[2] = "4:B5:B8";
    data.pos_map[3] = "5:D7:H7";
    data.pos_map[4] = NULL;
    data.board = create_empty_map();
    data.board[2][2] = 'x';
    cr_assert_eq(check_if_it_touches_the_player("A1"), 0);
    cr_assert_eq(check_if_it_touches_the_player("A2"), 0);
    free(data.board);
    free(data.pos_map);
}

Test(check_if_it_touches_the_player, return1)
{
    data.pos_map = malloc(sizeof(char *) * (4 + 1));
    data.pos_map[0] = "2:C1:C2";
    data.pos_map[1] = "3:D4:F4";
    data.pos_map[2] = "4:B5:B8";
    data.pos_map[3] = "5:D7:H7";
    data.pos_map[4] = NULL;
    data.board = create_empty_map();
    data.board[2][2] = 'x';
    cr_assert_eq(check_if_it_touches_the_player("C1"), 1);
    cr_assert_eq(check_if_it_touches_the_player("E7"), 1);
    free(data.board);
    free(data.pos_map);
}