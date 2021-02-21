/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function for corewar
*/

#include "corewar.h"

int display_help(char *binary_name)
{
    my_putstr(1, "USAGE\n\t");
    my_putstr(1, binary_name);
    my_putstr(1, " [-dump nbr_cycle] [[-n prog_number] \
[-a load_adresses] prog_name] ...\n\n");
    my_putstr(1, "DESCRIPTION\n\t");
    my_putstr(1, "-dump nbr_cycle dumps the memory after the nbr_cycle \
execution (if the round isn't\n\t\t\talready over) with the following format: \
32 bytes/line in\n\t\t\thexadecimal (AOBCDEFE1DD3...)\n\t");
    my_putstr(1, "-n prog_number  sets the next program's number.  By default, \
the first free number\n\t\t\tin the parameter order\n\t");
    my_putstr(1, "-a load_address sets the next program's loading address.  \
When no address is\n\t\t\tspecified, optimize the addresses so that the process\
es ar as far\n\t\t\taway from each other as prossible.  \
The addresses are MEM_SIZE modulo\n");
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (ac <= 1) {
        my_putstr(2, "Error : Enter at least one champion\n");
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (display_help(av[0]));
    main_corewar(av, ac);
    return (0);
}