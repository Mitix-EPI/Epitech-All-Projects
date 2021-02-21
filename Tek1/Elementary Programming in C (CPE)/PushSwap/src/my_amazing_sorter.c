/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_amazing_sorter
*/

#include "../include/my.h"

int check_smallest_nbr(int *array_a, push_swap_t *p)
{
    int smallest = 2147483647;

    for (int i = 0; i < p->size_a; i++)
        if (array_a[i] < smallest) {
            smallest = array_a[i];
            p->idx_min = i;
        }
    return (smallest);
}

int check_order(int *array_a, push_swap_t *p)
{
    for (int i = 1; i < p->size_a; i++)
        if (array_a[i - 1] > array_a[i])
            return (0);
    return (1);
}

int my_amazing_sorter(int *array_a, int *array_b, int size, push_swap_t *p)
{
    if (check_order(array_a, p))
        return (0);
    while (p->size_b != size) {
        my_choice(array_a, p);
        place_b(array_a, array_b, p);
        if (p->size_b != size)
            my_putstr(" ");
    }
    for (int i = 0; i < size; i++) {
        my_putstr(" ");
        place_a(array_a, array_b, p);
    }
    return (0);
}

void end(int *array1, int *array2)
{
    my_putstr("\n");
    free(array1);
    free(array2);
}

int main_pushswap(int ac, char **av)
{
    push_swap_t push;
    int print = 0;
    int *array1;
    int *array2;
    push.size_a = ac -1;
    push.size_b = 0;

    array1 = malloc(sizeof(array1) * (ac));
    array2 = malloc(sizeof(array2) * (ac));
    for (int i = 0; i < push.size_a; i++)
        array1[i] = my_getnbr(av[i + 1]);
    my_amazing_sorter(array1, array2, push.size_a, &push);
    end(array1, array2);
    return (0);
}