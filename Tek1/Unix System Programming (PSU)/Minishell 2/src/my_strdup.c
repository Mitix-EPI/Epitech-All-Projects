/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** return value
*/

#include <stdlib.h>

int my_count_str1(char const *src)
{
    int i = 0;

    while (src && src[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strdup(char const *src)
{
    int n = my_count_str1(src);
    char *str = malloc(sizeof(char) * (n + 1));
    int i = 0;

    if (!src) {
        free(str);
        return (NULL);
    }
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}