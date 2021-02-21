/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** l_flags2
*/

#include "../include/my.h"

void print_first_perm(struct stat my_stat)
{
    if (S_ISDIR(my_stat.st_mode)) {
        my_putstr("d");
        return;
    }
    if (S_ISCHR(my_stat.st_mode)) {
        my_putstr("c");
        return;
    }
    if (S_ISBLK(my_stat.st_mode)) {
        my_putstr("b");
        return;
    }
    my_putstr((S_ISDIR(my_stat.st_mode)) ? "d" : "-");
    return;
}

void print_permissions(struct stat my_stat)
{
    print_first_perm(my_stat);
    my_putstr((my_stat.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((my_stat.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((my_stat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((my_stat.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((my_stat.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((my_stat.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((my_stat.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((my_stat.st_mode & S_IWOTH) ? "w" : "-");
    if (!(my_stat.st_mode & __S_ISVTX))
        my_putstr((my_stat.st_mode & S_IXOTH) ? "x" : "-");
    else
        my_putstr((my_stat.st_mode & S_IXOTH) ? "t" : "T");
    my_putstr(" ");
}

void print_hard_link(struct stat my_stat)
{
    my_put_nbr(my_stat.st_nlink);
    my_putstr(" ");
}

void print_owner(struct stat my_stat)
{
    struct passwd *pass;
    struct group *grp;

    pass = getpwuid(my_stat.st_uid);
    my_putstr(pass->pw_name);
    my_putstr(" ");
    grp = getgrgid(my_stat.st_gid);
    my_putstr(grp->gr_name);
    my_putstr(" ");
}

void print_size(struct stat my_stat)
{
    if (!S_ISCHR(my_stat.st_mode) && !S_ISBLK(my_stat.st_mode)) {
        my_put_nbr(my_stat.st_size);
        my_putstr(" ");
    } else {
        my_put_nbr(MAJOR(my_stat.st_rdev));
        my_putstr(" ");
        my_put_nbr(MINOR(my_stat.st_rdev));
        my_putstr(" ");
    }
}