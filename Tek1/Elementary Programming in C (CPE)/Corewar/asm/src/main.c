/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "asm.h"

int display_help(char *binary_name)
{
    my_putstr(1, "USAGE:\n\t");
    my_putstr(1, binary_name);
    my_putstr(1, " file_name[.s]\n\nDESCRIPTION\n\tfile_name\t");
    my_putstr(1, "file in assembly language to be converted into \
file_name.cor, an\n\t\t\texecutable in the Virtual Machine.\n");
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (display_help(av[0]));
    if (ac != 2)
        return (84);
    main_asm(av[1], env);
    return (0);
}