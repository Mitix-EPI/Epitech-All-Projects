/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** ls_args
*/

#include "../include/my.h"

int boolen_condition(char *name)
{
    if ((name[0] != '.' && name[1] != '.') ||
    (name[0] != '.' && name[1] != '\0'))
        return (1);
    return (0);
}

int if_else_ls_args(int *flags, char **av, int count, struct stat *mystat)
{
    if ((mystat->st_mode & __S_IFMT) == __S_IFDIR) {
        flags[5] = 1;
        if (ls_folder(flags, av, count, mystat))
            return (1);
    } else {
        flags[5] = 0;
        print_flag(flags, *mystat, NULL, av[count]);
        flags[5] = 1;
    }
    return (0);
}

int ls_args(int ac, char **av, int *flags)
{
    int count = 1;
    struct stat mystat;

    for (; count < ac; count++) {
        if (av[count][0] != '-') {
            if (lstat(av[count], &mystat) < 0)
                return (1);
            if (if_else_ls_args(flags, av, count, &mystat))
                return (1);
        }
    }
    return (0);
}