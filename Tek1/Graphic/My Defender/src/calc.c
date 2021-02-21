/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

float croix(int temp, char mode, sprite_t *sprite)
{
    if (mode == 'h')
        return (temp * sprite->weidth / 1080);
    if (mode == 'l')
        return (temp * sprite->hight / 1920);
}

int calc_coeff(int temp, char mode, sprite_t *sprite)
{
    float res1 = 0;
    int res2 = 0;
    float rest1 = 0;
    float rest2 = 0;

    if (mode == 'h')
        res1 = temp * sprite->weidth / 1080;
    if (mode == 'l')
        res1 = temp * sprite->hight / 1920;
    res2 = (int)res1;
    rest1 = res1 - (float)res2;
    rest2 = res1 - ((float)res2 + 1);
    if (rest1 > rest2)
        return (res2 + 1);
    else
        return (res2);
}