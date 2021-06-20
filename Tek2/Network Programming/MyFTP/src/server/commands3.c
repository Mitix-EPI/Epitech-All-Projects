/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** commands3
*/

#include "server/my_ftp.h"

int delete_file(char *filePath)
{
    if (remove(filePath) == 0)
        return 1;
    else
        return 0;
}

int change_dir(char *path)
{
    char *res = realpath(path, NULL);

    if (res && chdir(path) != -1)
        return 1;
    else
        return 0;
}