/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** needforspeed
*/

#ifndef NEEDFORSPEED_H_
#define NEEDFORSPEED_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int ai(void);
float *get_info_lidar(void);
float *parse_get_info_lidar(char *buffer);
float parse_get_current_speed(char *buffer);
float parse_get_current_wheels(char *buffer);
float float_from_buffer(char *buffer, int old_i, int i);
void set_forward(float speed);
void my_ftoa(float n, char *res, int afterpoint);
void my_putstr(int a, char const *str);
float get_current_speed(void);
float get_current_wheels(void);
void set_wheels_dir(float dir);
void set_backwards(float speed);
int condition2(float *rays, float cond);
int condition1(float *rays, float cond);
void write_stop_simulation(void);

#endif /* !NEEDFORSPEED_H_ */
