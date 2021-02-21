/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


typedef struct solver_s
{
    int x_max;
    int y_max;
}solver_t;

int end_solver(char *map, int x);

char *handle_error(char *filename, solver_t *solv);

int solvemaze(char *mapa, int x_max, int y_max);

#include "my.h"
#endif /* !SOLVER_H_ */