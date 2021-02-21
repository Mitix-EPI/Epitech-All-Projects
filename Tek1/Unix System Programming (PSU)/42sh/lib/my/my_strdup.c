/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Strdup
*/

#include <stdlib.h>
#include <string.h>

int my_strlen(const char *);

char *my_strcpy(char *, char const *);

char    *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    str = my_strcpy(str, src);
    return (str);
}