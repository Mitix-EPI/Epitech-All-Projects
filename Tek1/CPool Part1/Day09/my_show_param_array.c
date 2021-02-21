/*
** EPITECH PROJECT, 2019
** my_show_param_array.c
** File description:
** show struc
*/

#include "include/my.h"

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[0].copy != '\0'; i++) {
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_putstr(par[i].copy);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        my_putchar('\n');
    }
    return (0);
}
