/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** flags_3
*/

#include "include/my.h"

void is_array(va_list ap)
{
    char **s = va_arg(ap, char **);

    for (int i = 0; s[i] != NULL; i++) {
        my_putstr(s[i]);
        my_putchar(' ');
    }
}

void is_int_star(va_list ap)
{
    int *s = va_arg(ap, int *);

    for (int i = 0; s[i] != 0; i++) {
        my_put_nbr_base(s[i], "0123456789");
        my_putchar(' ');
    }
}

void (is_raimbow_str(va_list ap))
{
    int color = 1;
    char *str = va_arg(ap, char *);

    for (int i = 0; str[i]; i++, color++) {
        if (color > 7)
            color = 1;
        my_print_color(color);
        write(1, &str[i], 1);
        my_putstr("\033[0m");
    }
}

void my_print_color(int color)
{
    if (color == 1)
        my_putstr("\033[31;40m");
    if (color == 2)
        my_putstr("\033[32;40m");
    if (color == 3)
        my_putstr("\033[33;40m");
    if (color == 4)
        my_putstr("\033[34;40m");
    if (color == 5)
        my_putstr("\033[35;40m");
    if (color == 6)
        my_putstr("\033[36;40m");
    if (color == 7)
        my_putstr("\033[2;33;40m");
}