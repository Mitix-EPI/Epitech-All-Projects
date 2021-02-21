/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** ls_folder
*/

#include "../include/my.h"

int end_ls_folder(int *flags, DIR *mydir)
{
    if (flags[5] == 1 && flags[1] == 1)
        my_putstr("total 0\n");
    closedir(mydir);
    return (0);
}

int condition_ls_folder(int *flags, char **av, int count)
{
    if (flags[3] == 1) {
        t_flag(av[count], flags);
        flags[5] += 1;
        return (1);
    }
    return (0);
}

int ls_folder(int *flags, char **av, int count, struct stat *mystat)
{
    DIR *mydir = opendir(av[count]);
    struct dirent *myfile;
    char *path = NULL;

    if (!mydir)
        return (1);
    while ((myfile = readdir(mydir)) != NULL) {
        if (boolen_condition(myfile->d_name)) {
            if (condition_ls_folder(flags, av, count))
                break;
            path = my_strcat(av[count], myfile->d_name);
            if (lstat(path, mystat) < 0)
                return (1);
            free(path);
            if (print_flag(flags, *mystat, av[count], myfile->d_name) == 1)
                return (0);
            flags[5] += 1;
        }
    }
    return (end_ls_folder(flags, mydir));
}