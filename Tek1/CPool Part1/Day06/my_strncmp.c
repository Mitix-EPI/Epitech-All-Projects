/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** reproduce behavior function strncmp
*/
#include <string.h>

int my_count_str_(char const *s)
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    char a;
    char b;
    int i = 0;
    int res1 = my_count_str_(s1);
    int res2 = my_count_str_(s2);
    
    while (s1[i] != '\0' || i <= n) {
        a = s1[i];
        b = s2[i];
        if (a < b || a > b)
            return (a-b);
        i++;
    }
    return (0);
}
