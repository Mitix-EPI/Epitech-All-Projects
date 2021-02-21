/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct square
{
    long size_file;

    int start;
    int nb_lines;
    int nb_char;

    int size_square;
    int x0;
    int nb_line_square;
}square_t;

typedef struct change_to_int
{
    char c;
    int nb;
}change_to_int_t;

char *bsq_reader(char *map, long size);
int my_putstr(char const *str);
int my_getnbr(char const *str);
void bsq_find_biggest_square(char *map, long size);
int calc_start(char *map);
int calc_pos(int i, int j, int nb_char);
int calc_min(int *m_i, int i, int j, int nb_c);
void calc_int(int *map_int, square_t *sq_c);
char *my_revstr(char *str, long size_file);
int my_linelen(char *map);
void my_print_color(char c, int color);

#endif /* !MY_H_ */
