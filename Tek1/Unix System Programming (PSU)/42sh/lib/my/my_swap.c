/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** Swap two integers as pointers
*/

void   my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}