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
#include <sys/types.h>
#include <sys/stat.h>
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

//main.c
int main(int ac, char **av);

//main_bsq.c
int main_bsq(int ac, char **av);
int check_args(int ac, char **av);

//bsq_reader.c
char *bsq_reader(char *map, long size);

//bsq_find_biggest_square.c
void coord_biggest_square(char *map, int *map_int, square_t *sq_c);
void rem_numbers(char *map, square_t *sq_c);
void bsq_find_biggest_square(char *map, long size);

//my_print_map.c
void print_x_square(char *map, int *map_int, square_t *sq_c);
void print_map(char *map, int size);

//calc.c
int calc_start(char *map);
int calc_min(int *m_i, int i, int j, int nb_c);
void calc_int(int *map_int, square_t *sq_c);
int my_linelen(char *map);

//my_getnbr.c
int my_getnbr(char const *str);
int my_isnumb(char const c);

//my_revstr.c
char *my_revstr(char *str, long size_file);
char *put_str_into_str(char *str, char *reverse);

#endif /* !MY_H_ */
