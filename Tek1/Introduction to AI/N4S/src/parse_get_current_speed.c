/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** parse_get_current_speed
*/

#include "needforspeed.h"

float float_from_buffer(char *buffer, int old_i, int i)
{
    float ret = 0;
    char *tmp = malloc(sizeof(char) * (i - old_i + 2));
    int count = 0;

    tmp[i - old_i + 1] = 0;
    for (; count < i - old_i + 1; count++, old_i++) {
        tmp[count] = buffer[old_i];
    }
    tmp[count] = 0;
    ret = atof(tmp);
    return (ret);
}

float parse_get_current_speed(char *buffer)
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
