/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverse string
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int j = 0;
    char *goodstr = malloc(sizeof(char) * (len + 1));
    goodstr[len] = 0;

    for (; str[i]; i++);
    for (i -= 1; i >= 0; i--, j++) {
        goodstr[j] = str[i];
    }
    goodstr[j] = 0;
    return (goodstr);
}