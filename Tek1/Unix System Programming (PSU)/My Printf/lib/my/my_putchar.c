/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char const c)
{
    write(1, &c, 1);
}