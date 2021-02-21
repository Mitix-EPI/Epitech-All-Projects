/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_main_player1
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_touch, return_0)
{
    char *txt = malloc(sizeof(char) * (3));
    txt[0] = 'A';
    txt[1] = '1';
    txt[2] = 0;
    data.pos_map = malloc(sizeof(char *) * (4 + 1));
    data.pos_map[0] = "2:C1:C2";
    data.pos_map[1] = "3:D4:F4";
    data.pos_map[2] = "4:B5:B8";
    data.pos_map[3] = "5:D7:H7";
    data.pos_map[4] = NULL;
    data.board = create_empty_map();
    data.board[2][2] = 'x';
    cr_assert_eq(check_touch(txt), 0);
    free(data.board);
    free(data.pos_map);
    free(txt);
}

Test(check_touch, return_1)
{
    char *txt = malloc(sizeof(char) * (3));
    txt[0] = 'C';
    txt[1] = '1';
    txt[2] = 0;
    data.pos_map = malloc(sizeof(char *) * (4 + 1));
    data.pos_map[0] = "2:C1:C2";
    data.pos_map[1] = "3:D4:F4";
    data.pos_map[2] = "4:B5:B8";
    data.pos_map[3] = "5:D7:H7";
    data.pos_map[4] = NULL;
    data.board = create_empty_map();
    data.board[2][2] = 'x';
    cr_assert_eq(check_touch(txt), 1);
    free(data.board);
    free(data.pos_map);
    free(txt);
}

Test(sets, return_nothing)
{
    sets("pos1");
}