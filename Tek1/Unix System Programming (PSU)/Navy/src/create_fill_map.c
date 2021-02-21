/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** create_fill_map
*/

#include "../include/my.h"

void put_line_in_map(char **map, char *str)
{
    int width = str[0] - 48;
    int y = 0;
    int x = 0;

    for (x = 0; map[0][x] != '\n'; x++)
        if (map[0][x] == str[2])
            break;
    if (str[2] == str[5]) {
        y = str[3] - '0' + 1;
        for (int count = 0; count < width; count++, y++)
            map[y][x] = str[0];
    } else {
        y = str[3] - '0' + 1;
        for (int count = 0; count < width; x++)
            if (map[y][x] == '.') {
                map[y][x] = str[0];
                count++;
            }
    }
}

char **create_fill_map(char *path)
{
    char **map = create_empty_map();
    int fd = open(path, O_RDONLY);
    char *line = NULL;

    while (1) {
        line = get_next_line(fd);
        if (!line)
            break;
        put_line_in_map(map, line);
    }
    close(fd);
    return (map);
}