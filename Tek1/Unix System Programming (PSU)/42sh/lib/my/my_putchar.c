/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display a string
*/

int write(int b, char *c, int s);

int    my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}