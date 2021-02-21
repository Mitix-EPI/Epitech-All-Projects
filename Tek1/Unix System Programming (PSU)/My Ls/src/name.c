/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** name
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}

char *name_file(char *str)
{
    int i = 0;
    int a = 0;
    int booleen = 0;
    int str_size = my_strlen(str);
    char *tmp = NULL;
    int count = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '/') {
            a = i;
            booleen = 1;
        }
    if (booleen == 0)
        return (str);
    count = str_size - a;
    tmp = malloc(sizeof(tmp) * (count) + 1);
    tmp[count] = 0;
    for (count -= 1, i = str_size; str[i] != '/'; i--, count--)
        tmp[count] = str[i];
    return (tmp);
}