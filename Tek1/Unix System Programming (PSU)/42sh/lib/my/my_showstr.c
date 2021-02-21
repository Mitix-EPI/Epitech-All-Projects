/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** Show str
*/

int my_putchar(char);

void    my_show_hex(char c)
{
    if (c < 10)
        my_putchar('0' + c);
    else
        my_putchar('a' + c - 10);
}

int    my_showstr(char const *str)
{
    while (*str) {
        if (*str == 127 || *str < 32) {
            my_putchar('\\');
            my_show_hex(*str / 16);
            my_show_hex(*str / 16);
            my_show_hex(*str % 16);
        } else
            my_putchar(*str);
        str++;
    }
    return (0);
}