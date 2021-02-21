/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    if (ac > 1 && av[1])
        return (84);
    signal(SIGINT, siginhandler);
    return (mysh(env));
}
