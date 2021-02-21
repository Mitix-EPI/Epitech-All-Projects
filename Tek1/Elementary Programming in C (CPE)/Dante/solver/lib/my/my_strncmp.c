/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compares n char
*/

#include<stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n;) {
        if (!s1[i] || !s2[i])
            return 0;
        if (s1[i] == s2[i])
            i += 1;
        else
            return (s1[i] - s2[i]);
    }
    return 0;
}
