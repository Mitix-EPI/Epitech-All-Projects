/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** conditions
*/

#include "needforspeed.h"

int condition1(float *rays, float cond)
{
    if (rays[16] > cond && rays[15] > cond && rays[14] > cond &&
        rays[13] > cond && rays[12] > cond && rays[11] > cond &&
        rays[10] > cond && rays[17] > cond && rays[18] > cond &&
        rays[19] > cond && rays[20] > cond && rays[21] > cond &&
        rays[22] > cond)
        return (1);
    return (0);
}

int condition2(float *rays, float cond)
{
    if (rays[16] < cond && rays[15] < cond && rays[14] < cond &&
        rays[13] < cond && rays[12] < cond && rays[11] < cond &&
        rays[10] < cond && rays[17] < cond && rays[18] < cond &&
        rays[19] < cond && rays[20] < cond && rays[21] < cond &&
        rays[22] < cond)
        return (1);
    return (0);
}