/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** open_file
*/

#include "../my_tower.h"

char *map_reader(char *map, long size)
{
    int fd = 0;
    int reader = 0;
    char *buffer = malloc(sizeof(char) * size + 1);

    for (int a = 0; a < size; a += 1)
        buffer[a] = '\0';
    fd = open(map, O_RDONLY);
    if (fd == -1 || errno == 2 || errno == 21)
        return (NULL);
    reader = read(fd, buffer, size);
    if (reader > 0) {
        close(fd);
        return (buffer);
    }
    free(buffer);
    close(fd);
    return (NULL);
}