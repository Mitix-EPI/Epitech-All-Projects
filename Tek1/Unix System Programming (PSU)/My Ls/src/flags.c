/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** flags
*/

#include "../include/my.h"

int good_flags(char c, int *list_flag)
{
    switch (c) {
        case 'R':
            list_flag[0] = 1;
            return 1;
        case 'l':
            list_flag[1] = 1;
            return 1;
        case 'd':
            list_flag[2] = 1;
            return 1;
        case 't':
            list_flag[3] = 1;
            return 1;
        case 'p':
            list_flag[4] = 1;
            return 1;
        default:
            return 0;
    }
}

int check_flags(int ac, char **av, int *list_flags)
{
    if (ac == 1)
        return (0);
    for (int a = 1; a < ac; a++) {
        if (av[a][0] == '-') {
            for (int i = 1; av[a][i]; i++) {
                if (good_flags(av[a][i], list_flags) == 1);
                else
                    return (84);
            }
        }
    }
    return (0);
}

int check_only_flags(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-')
            return (0);
    }
    return (1);
}

int condition_print_flag(char *path, char *name)
{
    if (!path)
        print_name(name);
    else
        print_name(path);
    return (1);
}

int print_flag(int *flags, struct stat my_stat, char *path, char *name)
{
    if ((flags[2] == 1 && flags[1] == 0) || (flags[3] == 1 && flags[2] == 0))
        return (condition_print_flag(path, name));
    if (flags[2] == 1 && flags[1] == 1 && path[0] != '.' && path[1] != 0) {
        lstat(path, &my_stat);
        l_flags(my_stat);
        print_name(path);
        return (1);
    }
    if (flags[1] == 1) {
        if (path != NULL && flags[5] == 1 && flags[2] == 0)
            print_total(path);
        l_flags(my_stat);
        print_name(name);
    }
    if (flags[0] == 0 && flags[1] == 0 && flags[2] == 0 && flags[3] == 0
    && flags[4] == 0)
        print_name(name);
    return (0);
}