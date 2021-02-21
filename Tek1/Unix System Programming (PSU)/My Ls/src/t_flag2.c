/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** t_flags2
*/

#include "../include/my.h"

int count_file(char *path)
{
    DIR *mydir;
    struct dirent *myfile;
    int count = 0;

    mydir = opendir(path);
    while ((myfile = readdir(mydir)) != NULL)
        if ((myfile->d_name[0] != '.' && myfile->d_name[1] != '.') ||
        (myfile->d_name[0] != '.' && myfile->d_name[1] != '\0'))
            count += 1;
    closedir(mydir);
    return (count);
}

char **set_array(int nb_file, char *path)
{
    DIR *mydir;
    struct dirent *myfile;
    char **tmp = malloc(sizeof(tmp) * (nb_file + 1));

    tmp[nb_file] = NULL;
    mydir = opendir(path);

    for (int i = 0; i < nb_file && (myfile = readdir(mydir)) != NULL;) {
        if ((myfile->d_name[0] != '.' && myfile->d_name[1] != '.') ||
        (myfile->d_name[0] != '.' && myfile->d_name[1] != '\0')) {
            tmp[i] = myfile->d_name;
            i++;
        }
    }
    closedir(mydir);
    return (tmp);
}