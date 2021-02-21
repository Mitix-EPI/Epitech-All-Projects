/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** swap variables
*/

void my_swap(int *a, int *b)
{
    int cache = *a;

    *a = *b;
    *b = cache;
}
