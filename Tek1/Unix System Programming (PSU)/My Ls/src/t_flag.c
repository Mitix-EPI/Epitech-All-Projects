/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** r_flag
*/

#include "../include/my.h"

void score_condition(int mtime, int i, int *score, int *idx)
{
    if (mtime > *score) {
        *score = mtime;
        *idx = i;
    }
}

char *newest_first(int nb_file, char **names_files, char *path)
{
    struct stat mystat;
    int idx = 0;
    int score = 0;
    char *res = NULL;

    for (int i = 0; i < nb_file; i++) {
        if (names_files[i] != NULL) {
            if (path[1] != '\0') {
                res = my_strcat(path, names_files[i]);
                lstat(res, &mystat);
                free(res);
            }
            else if (lstat(names_files[i], &mystat) < 0)
                exit(84);
            score_condition(mystat.st_mtime, i, &score, &idx);
        }
    }
    res = names_files[idx];
    names_files[idx] = NULL;
    return (res);
}

void end_t_flag(char **names_files, DIR *mydir, int nb_file)
{
    for (int i = 0; i < nb_file; i++)
        free(names_files[i]);
    free(names_files);
    closedir(mydir);
}

void condition_t_flag(char *path, char *answer)
{
    char *tmp = NULL;
    struct stat mystat;

    if (path[0] != '.' && path[1] != 0) {
        tmp = my_strcat(path, answer);
        lstat(tmp, &mystat);
        free(tmp);
    } else
        lstat(answer, &mystat);
    l_flags(mystat);
}

void t_flag(char *path, int *flags)
{
    DIR *mydir;
    int nb_file = count_file(path);
    char **names_files = set_array(nb_file, path);
    char *answer = NULL;

    mydir = opendir(path);
    for (int i = 0; i < nb_file; i++) {
        answer = newest_first(nb_file, names_files, path);
        if (flags[1] == 1)
            condition_t_flag(path, answer);
        print_name(answer);
    }
    end_t_flag(names_files, mydir, nb_file);
}