/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** l_flags
*/

#include "../include/my.h"

void print_date(struct stat my_stat)
{
    char *str = ctime(&my_stat.st_mtime);
    for (int i = 4; i < 16; i++) {
            write(1, &str[i], 1);
    }
    my_putstr(" ");
}

void end_print_total(int total, DIR *mydir)
{
    my_putstr("total ");
    my_put_nbr(total / 2);
    my_putstr("\n");
    closedir(mydir);
}

int condition_total(char *name, int total)
{
    struct stat mystat;

    if (name[0] != '.' && name[1] != '\0') {
        lstat(name, &mystat);
        total += mystat.st_blocks;
    }
    return (total);
}

void print_total(char *path)
{
    DIR *mydir;
    struct stat mystat;
    struct dirent *myfile;
    int total = 0;
    char *tmp = NULL;

    mydir = opendir(path);
    while ((myfile = readdir(mydir)) != NULL) {
        if (path[0] == '.' && path[1] == 0) {
            total = condition_total(myfile->d_name, total);
        } else {
            if (myfile->d_name[0] != '.' && myfile->d_name[1] != '\0') {
                tmp = my_strcat(path, myfile->d_name);
                lstat(tmp, &mystat);
                total += mystat.st_blocks;
                free(tmp);
            }
        }
    }
    end_print_total(total, mydir);
}

void l_flags(struct stat my_stat)
{
    print_permissions(my_stat);
    print_hard_link(my_stat);
    print_owner(my_stat);
    print_size(my_stat);
    print_date(my_stat);
}