/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    sokoban_t s;
    if (ac == 1)
        return (84);
    return (main_sokoban(ac, av, &s));
}