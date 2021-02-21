/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_main_player2
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_free(char *txt, char **map1, char **map2)
{
    free(txt);
    free(map1);
    free(map2);
}

Test(send_hit_or_missed, return_nothing)
{
    char *txt = malloc(sizeof(char) * 3);

    data.pid = 10000;
    data.pos_map = malloc(sizeof(char *) * (4 + 1));
    data.pos_map[0] = "2:C1:C2";
    data.pos_map[1] = "3:D4:F4";
    data.pos_map[2] = "4:B5:B8";
    data.pos_map[3] = "5:D7:H7";
    data.pos_map[4] = NULL;
    data.board = create_empty_map();
    data.board[2][2] = 'x';
    txt[0] = 'A';
    txt[1] = '1';
    txt[2] = 0;
    send_hit_or_missed(txt);
    txt[0] = 'C';
    txt[1] = '2';
    send_hit_or_missed(txt);
    my_free(txt, data.board, data.pos_map);
}