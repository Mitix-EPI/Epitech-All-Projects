/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** realloc_array
*/

#include "lemin.h"

char **copy_arrays(char **dest, char **src)
{
    for (int i = 0; src[i] != NULL; i++) {
        dest[i] = my_strcpy(src[i]);
    }
    return (dest);
}

int count_arr(char **arr)
{
    int len = 0;

    for (; arr[len] != NULL; len++);
    return (len);
}

char **realloc_array(char **arr, char *str)
{
    int len = count_arr(arr);
    char **new = malloc(sizeof(char *) * (len + 1 + 1));

    new = copy_arrays(new, arr);
    new[len + 1] = NULL;
    new[len] = my_strcpy(str);
    for (int i = 0 ; arr[i] ; ++i)
        free(arr[i]);
    free(arr);
    return (new);
}