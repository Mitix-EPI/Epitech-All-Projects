/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** error_handling
*/

#include "../include/my.h"

int error_handling_tetrimino(int ac, char **av)
{
    DIR *mydir = opendir("./tetriminos");
    struct dirent *myfile;
    struct stat sb;
    char **name_files = NULL;
    int count = 0;

    if (!mydir) {
        return (84);
    }
    for (; (myfile = readdir(mydir)) != NULL;) {
        if (dot_tetrimino(myfile->d_name) == 1)
            return (0);
    }
    return (84);
}

int error_handling(int ac, char **av)
{

    if (check_flags(ac, av) == 84)
        return (84);
    if (error_handling_tetrimino(ac, av) == 84)
        return (84);
    return (0);
}
