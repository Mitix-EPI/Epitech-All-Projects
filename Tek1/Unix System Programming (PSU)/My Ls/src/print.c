/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** print
*/

#include "../include/my.h"

void print_name(char *str)
{
    my_putstr(str);
    my_putstr("\n");
}

int print_error(void)
{
    write(2, "error\n", 7);
    return (84);
}