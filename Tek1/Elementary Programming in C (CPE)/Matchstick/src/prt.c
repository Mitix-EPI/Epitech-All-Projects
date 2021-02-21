/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** prt
*/

#include "../include/my.h"

int prt_rtn(char *str)
{
    for (int x = 0; str[x]; x++)
        write(1, &str[x], 1);
    return (0);
}