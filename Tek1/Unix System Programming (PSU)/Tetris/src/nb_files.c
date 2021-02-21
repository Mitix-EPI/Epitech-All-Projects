/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** nb_files
*/

#include "../include/my.h"

int count_nb_files(void)
{
    DIR *mydir = opendir("./tetriminos");
    struct dirent *myfile;
    int i = 0;

    while ((myfile = readdir(mydir)) != NULL) {
    	i++;
    }
    closedir(mydir);
    return (i);
}

int nb_files_loop(char **name_files, DIR *dir, int i)
{
    struct dirent *file;
    for (; (file = readdir(dir)) != NULL;) {
        if (dot_tetrimino(file->d_name) == 1) {
            name_files[i] = my_strdup(file->d_name);
            i++;
        }
    }
    return (i);
}

char **display_nb_files(tetris_t *tetris)
{
    DIR *mydir = opendir("./tetriminos");
    char **name_files = NULL;
    int count = 0;
    int i = 0;

    if (!mydir)
        return (NULL);
    count = count_nb_files() - 2;
    if (count < 1)
        return (NULL);
    if (tetris->debug == 1)
        my_printf("Tetriminos : %d\n", count);
    tetris->tetrimino = malloc(sizeof(tetrimino_t) * (count + 1));
    tetris->tetrimino[count].type = NULL;
    tetris->nb_tetriminos = count;
    name_files = malloc(sizeof(char *) * (count + 1));
    i = nb_files_loop(name_files, mydir, i);
    name_files[i] = NULL;
    closedir(mydir);
    return (name_files);
}
