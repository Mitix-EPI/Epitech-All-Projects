/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** reproduce str cmp fonction
*/

#include "../include/my.h"

int my_count(char const *s)
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    char a;
    char b;
    int i = 0;
    int res1 = my_count(s1);
    int res2 = my_count(s2);

    while (s1[i] != '\0'){
        a = s1[i];
        b = s2[i];
        if (a < b || a > b)
            return (a-b);
        i++;
    }
    if (res1 < res2)
        return (- s2[i]);
    return (0);
}
