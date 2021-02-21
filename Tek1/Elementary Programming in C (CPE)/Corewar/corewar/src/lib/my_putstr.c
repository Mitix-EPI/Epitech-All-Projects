/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(const int fd, char c)
{
    write(fd, &c, 1);
}

void my_putstr(const int fd, char *str)
{
    for (int i = 0; str && str[i]; i++)
        write(fd, &str[i], 1);
}