/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** return value
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
