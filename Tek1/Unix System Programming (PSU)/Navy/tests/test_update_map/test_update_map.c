/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_update_map
*/

#include "../../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(update_board, return_an_updated_map)
{
    char **board = create_empty_map();
    char *txt = malloc(sizeof(char) * (3));
    txt[0] = 'A';
    txt[1] = '1';
    txt[2] = 0;
    update_board(board, txt, 1);
    update_board(board, txt, 0);
}