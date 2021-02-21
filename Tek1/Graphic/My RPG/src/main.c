/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "rpg.h"
#include "my.h"

int man(void)
{
    my_putstr("RPG\n\nUSAGE:\n\t./my_rpg\n\n");
    my_putstr("HISTORY:\n\tThe lockdown is announced, but you don't want to ");
    my_putstr("respect it !\n\tYou want to join your girlfriend to ... \n");
    my_putstr("\tYou know what I mean !\n\n\t");
    my_putstr("Recup a box of condoms, a Corona and hydroalcoholic gel to\n");
    my_putstr("\tto seduce your girlfriend\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 2) {
        write(2, "Too much arguments.\n", 20);
        write(2, av[0], my_strlen(av[0]));
        write(2, " -h for help", 12);
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (man());
    else if (ac == 2) {
        write(2, "Invalid argument.\n", 20);
        write(2, av[0], my_strlen(av[0]));
        write(2, " -h for help", 12);
        return (84);
    }
    return (main_rpg());
}