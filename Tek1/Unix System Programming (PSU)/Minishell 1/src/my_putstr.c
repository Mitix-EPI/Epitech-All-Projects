/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_putstr
*/

#include <unistd.h>

void *my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
    return (0);
}
