/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** paths
*/

#include "asm.h"

int exact_extension(char *path, char *ext)
{
    int index_path = 0;
    int index_ext = 0;

    for (; path[index_path]; index_path += 1);
    for (; ext[index_ext]; index_ext += 1);
    for (; index_path >= 0 && index_ext >= 0;) {
        if (path[index_path--] != ext[index_ext--])
            return (0);
    }
    return (1);
}

char *return_good_path(char *path)
{
    int len = my_strlen(path) + 2;
    char *good_path = malloc(sizeof(char) * (len + 1));
    int j = 3;

    fill_str(good_path, len, '\0');
    path = my_revstr(path);
    good_path[0] = 'r';
    good_path[1] = 'o';
    good_path[2] = 'c';
    for (int i = 1; path && path[i]; i++, j++) {
        good_path[j] = path[i];
    }
    good_path = my_revstr(good_path);
    return (good_path);
}
