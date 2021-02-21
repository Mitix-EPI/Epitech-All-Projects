/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "../include/my.h"
#include "../include/solver.h"
#include "../include/my_printf.h"
#include "../include/get_next_line.h"

int main(int ac, char **av)
{
    solver_t solv;
    char *map = NULL;

    if (ac != 2)
        return (84);
    map = handle_error(av[1], &solv);
    if (!map)
        return (84);
    solvemaze(map, solv.x_max, solv.y_max);
    return (0);
}
