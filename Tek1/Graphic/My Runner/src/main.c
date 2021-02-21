/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == 'h' || av[1][1] == 'h')
        return (print_help());
    return (main_my_runner(av[1]));
}