/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq_reader
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "include/my.h"

char *bsq_reader(char *map, long size)
{
    int fd = 0;
    int reader = 0;
    char *buffer = malloc(sizeof(char) * size + 1);

    fd = open(map, O_RDONLY);
    reader = read(fd, buffer, size);
    if (reader > 0) {
        close(fd);
        return (buffer);
    }
    free(buffer);
    close(fd);
    exit(84);
}