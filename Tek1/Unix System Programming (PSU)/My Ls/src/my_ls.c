/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls
*/

#include "../include/my.h"

int ls_root(char **av, int *flags)
{
    struct stat mystat;
    DIR *mydir;
    struct dirent *myfile;

    mydir = opendir(av[1]);
    flags[5] = 1;
    while ((myfile = readdir(mydir)) != NULL) {
        if (lstat(myfile->d_name, &mystat) < 0)
            return (print_error());
        if ((myfile->d_name[0] != '.' && myfile->d_name[1] != '.') ||
        (myfile->d_name[0] != '.' && myfile->d_name[1] != '\0')) {
            if (flags[3] == 1) {
                t_flag(".", flags);
                return (0);
            }
            print_flag(flags, mystat, ".", myfile->d_name);
            flags[5] = 0;
        }
    }
    closedir(mydir);
    return (0);
}

int d_ls_root(char **av, int *flags)
{
    struct stat mystat;
    flags[5] = 1;

    if (lstat(av[1], &mystat) < 0)
        return (print_error());
    print_flag(flags, mystat, ".", av[1]);
    return (0);
}

int my_ls(int ac, char **av)
{
    int flags[6] = {0, 0, 0, 0, 0, 1};

    if (check_flags(ac, av, flags) == 84)
        return (print_error());
    if (ac == 1 || check_only_flags(ac, av)) {
        av[1] = ".";
        if (flags[2] != 1) {
            if (ls_root(av, flags))
                return (print_error());
        } else {
            if (d_ls_root(av, flags))
                return (print_error());
        }
        return (0);
    }
    if (ls_args(ac, av, flags))
        return (print_error());
    return (0);
}