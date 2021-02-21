/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
typedef struct push_swap_s
{
    int size_a;
    int size_b;
    int idx_min;
}push_swap_t;

//main.c
int main(int ac, char **av);

//my_amazing_sorter.c
int my_amazing_sorter(int *array_a, int *array_b, int size, push_swap_t *p);
int main_pushswap(int ac, char **av);

//my_getnbr.c
int my_isnumb(char const c);
int my_getnbr(char const *str);

//swap.c
void swap(int *array, int size);
void rotate_left(int *array, push_swap_t *p);
void rotate_right(int *array, int size);
void place_b(int *array_a, int *array_b, push_swap_t *p);
void place_a(int *array_a, int *array_b, push_swap_t *p);
int my_choice(int *array_a, push_swap_t *p);

//my_putstr.c
int my_putstr(char const *str);

int check_smallest_nbr(int *array_a, push_swap_t *p);

#endif /* !MY_H_ */
