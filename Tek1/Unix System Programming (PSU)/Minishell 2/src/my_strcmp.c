/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcmp
*/

#include <string.h>

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

    while (s1[i] != '\0') {
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