/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main
*/

#include "include/my.h"

int check_args(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == 'h' || av[1][1] == 'h')) {
        write(1, "USAGE :\n\t./bsq <name_map>\n", 27);
        exit(0);
    }
    if (ac != 2)
        exit(84);
}

int main_bsq(int ac, char **av)
{
    char *map = NULL;
    struct stat fileStat;

    check_args(ac, av);
    if (stat(av[1], &fileStat) < 0)
        return (84);
    map = bsq_reader(av[1], fileStat.st_size);
    map[fileStat.st_size] = '\0';
    bsq_find_biggest_square(map, fileStat.st_size);
    free(map);
    return (0);
}