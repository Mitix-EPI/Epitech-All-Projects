/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Return number of characters who are in str
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
