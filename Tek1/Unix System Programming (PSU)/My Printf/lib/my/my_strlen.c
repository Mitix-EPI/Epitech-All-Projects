/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** count numbers of characters
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}
