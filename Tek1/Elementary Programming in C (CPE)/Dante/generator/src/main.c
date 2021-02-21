/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "generator.h"

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4)
        return (84);
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        create_perfect(my_getnbr(av[1]), my_getnbr(av[2]));
    if (ac == 3)
        create_imperfect(my_getnbr(av[1]), my_getnbr(av[2]));
    return (0);
}