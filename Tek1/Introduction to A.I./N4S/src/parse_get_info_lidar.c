/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** parse_get_indo_lidar
*/


#include "needforspeed.h"

float *parse_get_info_lidar(char *buffer)
{
    float *dist = malloc(sizeof(int) * (33 + 1));
    int i = 0;
    int old_i = 0;

    for (int count = 0; buffer && buffer[i] && count < 3; i++)
        if (buffer[i] == ':')
            count++;
    old_i = i - 1;
    for (int count = 0; buffer && buffer[i] && count < 33; i++) {
        if (buffer[i] == ':') {
            ++count;
            dist[count] = float_from_buffer(buffer, old_i + 1, i);
            old_i = i++;
        }
    }
    return (dist);
}
