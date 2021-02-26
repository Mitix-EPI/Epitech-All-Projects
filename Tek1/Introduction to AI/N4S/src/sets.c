/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** sets
*/

#include "needforspeed.h"

int check_if_end_sets(char *str)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == ':')
            count++;
        if (count == 3) {
            if (str[i + 1] == 'T')
                return (1);
            return (0);
        }
    }
    return (0);
}

void set_forward(float speed)
{
    char *line = malloc(sizeof(char) * 1000);
    char res[20] = {0};

    if (speed < 0 || speed > 1) {
        fprintf(stderr, "error argument\n");
        return;
    }
    if (check_if_end_sets(line)) {
        write_stop_simulation();
        exit(0);
    }
    write(1, "car_forward:", 12);
    my_ftoa(speed, res, 2);
    my_putstr(1, res);
    write(1, "\n", 1);
    read(0, line, 1000);
    free(line);
}

void set_backwards(float speed)
{
    char *line = malloc(sizeof(char) * 1000);
    char res[20] = {0};

    if (speed < 0 || speed > 1) {
        fprintf(stderr, "error argument\n");
        return;
    }
    if (check_if_end_sets(line)) {
        write_stop_simulation();
        exit(0);
    }
    write(1, "car_backwards:", 14);
    my_ftoa(speed, res, 2);
    my_putstr(1, res);
    write(1, "\n", 1);
    read(0, line, 1000);
    free(line);
}

void set_wheels_dir(float dir)
{
    char *line = malloc(sizeof(char) * 1000);
    char res[20] = {0};

    if (dir < -1 || dir > 1) {
        fprintf(stderr, "error argument\n");
        return;
    }
    if (check_if_end_sets(line)) {
        write_stop_simulation();
        exit(0);
    }
    write(1, "wheels_dir:", 11);
    my_ftoa(dir, res, 2);
    my_putstr(1, res);
    write(1, "\n", 1);
    read(0, line, 1000);
    free(line);
}
