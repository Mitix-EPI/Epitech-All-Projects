/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "include/my.h"

int check_args(int ac)
{
    if (ac != 2)
        exit(84);
}

int main(int ac, char **av)
{
    char *map;
    struct stat fileStat;

    check_args(ac);
    if (stat(av[1], &fileStat) < 0)
        return (84);
    map = bsq_reader(av[1], fileStat.st_size);
    map[fileStat.st_size] = '\0';
    bsq_find_biggest_square(map, fileStat.st_size);
    free(map);
    return (0);
}