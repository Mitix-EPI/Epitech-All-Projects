/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** check_if_h
*/

#include "../include/my.h"
#include <stdlib.h>

void print_h(void)
{
    my_putstr("Function my_printf :");
    my_putstr("\vint my_printf(char const *format, ...)\n");
    my_putstr("USAGE :\n\t%d : flag to display integers\n");
    my_putstr("\t%s : flag to display strings\n");
    my_putstr("\t%c : flag to display characters\n");
    my_putstr("\t%p : flag to display pointers adresses\n");
    my_putstr("\t%x : flag to display numbers to base 16 (min)\n");
    my_putstr("\t%X : flag to display numbers to base 16 (maj)\n");
    my_putstr("\t%o : flag to display numbers to base 8\n");
    my_putstr("\t%b : flag to display numbers to base 2\n");
    my_putstr("\t%u : flag to display only positives numbers\n");
    my_putstr("\t%% : flag to display % normally\n");
    my_putstr("\t%i : flag to display numbers positives and taller than ");
    my_putstr("integer\n");
    my_putstr("\t%a [BONUS] : flag to display char ** ");
    my_putstr("(don't forget 0 at the end of the char **)\n");
    my_putstr("\t%t [BONUS] : flag to display int * ");
    my_putstr("(don't forget 0 at the end of the int *)\n");
    my_putstr("\t%r [BONUS] : flag to display str whith raimbow color\n");
}

int check_if_h(char const *str)
{
    for (int i = 0; str[i+1]; i++)
        if (str[i] == '%')
            if (str[i + 1] == 'h') {
                print_h();
                return (0);
            }
    return (0);
}