/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main_navy
*/

#include "../include/my.h"

int main_navy(int ac, char **av)
{
    if (ac == 2)
        return (main_player_one(av));
    else if (ac == 3)
        return (main_player_two(av));
    return (84);
}