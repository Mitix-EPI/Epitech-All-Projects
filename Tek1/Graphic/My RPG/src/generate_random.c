/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_random
*/

#include "rpg.h"

int generate_random(int l, int r)
{
    return ((rand() % (r - l + 1)) + l);
}