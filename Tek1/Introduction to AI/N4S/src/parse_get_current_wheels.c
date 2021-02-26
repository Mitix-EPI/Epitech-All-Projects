/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** get_current_wheels
*/

#include "needforspeed.h"

float parse_get_current_wheels(char *buffer)
{
    float speed = 0;
    int i = 0;
    int next_i = 0;

    for (int count = 0; buffer && buffer[i] && count < 3; ++i)
        if (buffer[i] == ':')
            count++;
    ++i;
    next_i = i;
    for (; buffer && buffer[next_i] && buffer[next_i] != ':'; ++next_i);
    next_i--;
    speed = float_from_buffer(buffer, i, next_i);
    return (speed);
}
