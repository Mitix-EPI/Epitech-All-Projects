/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** srt cat
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = 0;
    while (dest[i] != '\0')
        i++;
    while (src[n] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_super_str_cat(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    int i = 0;

    for (; s1[i]; i += 1)
        dest[i] = s1[i];
    for (int j = 0; s2[j]; j += 1) {
        dest[i] = s2[j];
        i += 1;
    }
    dest[i] = 0;
    return (dest);
}