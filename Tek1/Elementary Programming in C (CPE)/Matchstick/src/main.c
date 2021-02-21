/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    return (main_matchstick(ac, av));
}