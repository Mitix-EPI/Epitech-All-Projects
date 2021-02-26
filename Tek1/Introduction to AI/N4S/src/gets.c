/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** gets
*/

#include "needforspeed.h"

int check_if_end_get_info_lidar(char *str)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == ':')
            count++;
        if (count == 35) {
            if (str[i + 1] == 'T')
                return (1);
            return (0);
        }
    }
    return (0);
}

float *get_info_lidar(void)
{
    char *line = malloc(sizeof(char) * 1000);
    float *ret = 0;

    write(1, "get_info_lidar\n", 15);
    read(0, line, 1000);
    if (check_if_end_get_info_lidar(line)) {
        write_stop_simulation();
        exit(0);
    }
    ret = parse_get_info_lidar(line);
    free(line);
    return (ret);
}

float get_current_speed(void)
{
    char *line = malloc(sizeof(char) * 1000);
    float ret = 0;

    write(1, "get_current_speed\n", 18);
    read(0, line, 1000);
    fprintf(stderr, "c'est la base : \n%s\n", line);
    ret = parse_get_current_speed(line);
    free(line);
    return (ret);
}

float get_current_wheels(void)
{
    char *line = malloc(sizeof(char) * 1000);
    float ret = 0;

    write(1, "get_current_wheels\n", 19);
    read(0, line, 1000);
    ret = parse_get_current_wheels(line);
    free(line);
    return (ret);
}
