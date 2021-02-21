/*
** EPITECH PROJECT, 2019
** my_join
** File description:
** Join arr
*/

#include "my.h"

char *my_arr_join(char **arr, char *join)
{
    char *ret = malloc(sizeof(char));
    int len = 0;

    ret[0] = '\0';
    for (; arr[len]; len++);
    if (len == 1) {
        ret = arr[0];
        return (ret);
    }
    for (int i = 0; arr[i]; i++) {
        ret = my_strcat2(ret, arr[i], -1, 0);
        if (i < len - 1)
            ret = my_strcat2(ret, join, -1, 0);
    }
    return (ret);
}