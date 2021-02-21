/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** swap
*/

#include "../include/my.h"

void rotate_left(int *array, push_swap_t *p)
{
    int cache = array[0];
    int i = 0;

    for (; i < p->size_a - 1; i++)
        array[i] = array[i + 1];
    array[i] = cache;
    my_putstr("ra");
}

void rotate_right(int *array, int size)
{
    int cache = array[size - 1];
    int i = 0;

    for (i = size - 1; i > 0; i--)
        array[i] = array[i - 1];
    array[i] = cache;
    my_putstr("rra");
}

void place_a(int *array_a, int *array_b, push_swap_t *p)
{
    int i = 0;

    if (p->size_a == 0) {
        array_a[0] = array_b[0];
    } else {
        for (i = p->size_a; i > 0; i--)
            array_a[i] = array_a[i - 1];
        array_a[i] = array_b[0];
    }
    for (i = 0; i < p->size_b - 1; i++)
        array_b[i] = array_b[i + 1];
    p->size_a++;
    p->size_b--;
    my_putstr("pa");
}

void place_b(int *array_a, int *array_b, push_swap_t *p)
{
    int i = 0;

    if (p->size_b == 0) {
        array_b[0] = array_a[0];
    } else {
        for (i = p->size_b; i > 0; i--)
            array_b[i] = array_b[i - 1];
        array_b[0] = array_a[0];
    }
    for (i = 0; i < p->size_a - 1; i++)
        array_a[i] = array_a[i + 1];
    p->size_b++;
    p->size_a--;
    my_putstr("pb");
}

int my_choice(int *array_a, push_swap_t *p)
{
    int ch = check_smallest_nbr(array_a, p);

    if ((p->idx_min) > (((p->size_a - 1) / 2) + 1)) {
        while (array_a[p->size_a - 1] != ch) {
            rotate_right(array_a, p->size_a);
            my_putstr(" ");
        }
        rotate_right(array_a, p->size_a);
        my_putstr(" ");
    } else {
        while (array_a[0] != ch) {
            rotate_left(array_a, p);
            my_putstr(" ");
        }
    }
}