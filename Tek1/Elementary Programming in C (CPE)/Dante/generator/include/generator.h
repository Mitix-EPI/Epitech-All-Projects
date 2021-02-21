/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

typedef struct vector_s
{
    int x;
    int y;
} vector_t;

typedef struct wall_s
{
    vector_t *walls;
    int possibilites;
} wall_t;

char **create_map2(int y, int x);
void fill_perfect_ite(char **map, int width, int heigth);
void create_perfect(int width, int heigth);
void create_imperfect(int width, int heigth);
char **create_map(int y, int x);
char **imperfect_generate(char **map, int w, int h);
void print_map(char **map, int width, int heigth);
void fill_perfect(char **map, int, int);
int if_condition(char **map, int i, int j);
#include "my.h"

#endif /* !GENERATOR_H_ */