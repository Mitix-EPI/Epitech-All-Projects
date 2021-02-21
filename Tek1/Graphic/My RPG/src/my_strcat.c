/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concats 2 strings
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlength(char *str)
{
    int size = 0;

    for (; str[size]; size += 1);
    return (size);
}

char *my_strcat(char *dest, char *src)
{
    int count = 0;
    int i = 0;
    char *res = NULL;

    count = my_strlength(dest) ;
    res = malloc(sizeof(char) * (count + my_strlength(src) + 1));
    while (dest[i] != '\0' && dest != NULL) {
        res[i] = dest[i];
        i += 1;
    }
    for (int j = 0; src[j]; j += 1) {
        res[i] = src[j];
        i += 1;
    }
    res[i] = '\0';
    return (res);
}