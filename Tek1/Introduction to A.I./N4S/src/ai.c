/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "needforspeed.h"

void write_start_simulation(void)
{
    char buffer[1024] = {0};

    write(1, "START_SIMULATION\n", 17);
    read(0, buffer, 1024);

}

void write_stop_simulation(void)
{
    char buffer[1024] = {0};

    write(1, "STOP_SIMULATION\n", 17);
    read(0, buffer, 1024);

}

char *clean_buffer(char *buffer)
{
    for (int i = 0; i < 1000; i++)
        buffer[i] = 0;
    return (buffer);
}

int ai(void)
{
    float dir = 0;
    float *rays = 0;

    write_start_simulation();
    while (1) {
        rays = get_info_lidar();
        if (rays[1] < 400)
            dir = ((rays[1] - 500) / 900);
        if (rays[32] < 400 && rays[1] > rays[32])
            dir = -((rays[32] - 500) / 900);
        set_wheels_dir(dir);
        if (condition1(rays, 700)) {
            set_forward(1);
            set_wheels_dir(0);
        } else if (condition2(rays, 200)) {
            set_wheels_dir(0);
            set_backwards(1);
        } else
            set_forward(1 - fabs(dir) - 0.25);
    }
    return (0);
}
