/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac == 1 || ((av[1][0] < 48 || av[1][0] > 57) && av[1][0] != '-')) {
        return (84);
    } else if (ac == 2) {
        write(1, "\n", 1);
        return (0);
    } else
        return (main_pushswap(ac, av));
}