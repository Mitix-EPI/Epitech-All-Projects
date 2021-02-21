/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_champ
*/

#include "corewar.h"

void fill_header(champions_t *champ, char *path)
{
    int fd = open(path, O_RDONLY);
    int size = 0;

    if (fd < 0)
        my_exit(CANT_OPEN_FILE);
    if (read(fd, &champ->header, sizeof(champ->header)) < 0) {
        close(fd);
        my_exit(CANT_READ_HEADER);
    }
    champ->header.prog_size = big_to_litlle(champ->header.prog_size);
    close(fd);
    champ->path = my_strdup(path);
}

void fill_instructs(champions_t *champ, char *path)
{
    int fd = open(path, O_RDONLY);
    int size = champ->header.prog_size;

    if (fd < 0)
        my_exit(CANT_OPEN_FILE);
    champ->instructs = malloc(sizeof(char) * (size + 2192 + 1));
    if (read(fd, champ->instructs, size + 2192) < 0) {
        close(fd);
        my_exit(CANT_READ_INSTRUCT);
    }
    champ->instructs[size + 2192] = '\0';
    champ->status = 1;
    champ->live = 0;
    champ->to_wait.ctw = 0;
    champ->to_wait.nb_toexe = 0;
    close(fd);
}

void fill_champ(champions_t *champ, char *path)
{
    fill_header(champ, path);
    fill_instructs(champ, path);
}
