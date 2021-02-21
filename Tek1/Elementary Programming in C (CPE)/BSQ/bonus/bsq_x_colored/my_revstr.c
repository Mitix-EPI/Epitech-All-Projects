/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverse string
*/

#include "include/my.h"

long count_char(char *str)
{
    long i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *put_str_into_str(char *str, char *reverse)
{
    long i = 0;

    while (str[i] != '\0'){
        str[i] = reverse[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *my_revstr(char *str, long size_file)
{

    long i = size_file - 1;
    char *reverse = malloc(sizeof(reverse) * (i + 1));
    long n = 0;

    while (i >= 0){
        reverse[n] = str[i];
        n++;
        i--;
    }
    reverse[n] = '\0';
    put_str_into_str(str, reverse);
    free(reverse);
    return (str);
}
