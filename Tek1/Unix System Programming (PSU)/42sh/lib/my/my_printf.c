/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printf command like
*/

#include <stdarg.h>
#include "my_printf.h"

char *str_move(char *);

void    print_format(int show_sign, char repet_c, int x, char *str)
{
    x = x - (my_strlen(str));
    int nb = my_getnbr(str);

    if (repet_c == ' ')
        for (int i = 0; i < x; i++)
            my_putchar(repet_c);
    if (nb < 0) {
        my_putchar('-');
        str = str_move(str);
    } else if (show_sign == 1) {
        my_putchar('+');
        x -= 1;
    }
    if (repet_c == '0')
        for (int i = 0; i < x; i++)
            my_putchar(repet_c);
    my_putstr(str);
}

return_func_t    run_func(char c, va_list ap)
{
    return_func_t ret;

    for (int i = 0; i != ARRAY_SIZE; i++)
        if (funcs[i].c == c) {
            ret.result = 1;
            ret.str = funcs[i].ptr(ap);
            return (ret);
        }
    ret.result = 0;
    ret.str = NULL;
    return (ret);
}

int    parse(int index, char *str, va_list ap)
{
    char repet_c = ' ';
    int show_sign = 0;
    char *nb = malloc(sizeof(int) + 1);
    return_func_t result;
    int x = 0;
    int nb_int = 0;

    my_memset(nb, 0, sizeof(int) + 1);
    for (int i = index + 1; str[i]; i++, x++) {
        if (str[i] == '0' && i == index + (show_sign == 1 ? 2 : 1))
            repet_c = '0', x--;
            continue;
        str[i] >= '0' && str[i] <= '9' ? nb[x] = str[i] : 0;
        if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u') {
            nb_int = my_getnbr(nb);
            result = run_func(str[i], ap);
            print_format(show_sign, repet_c, nb_int, result.str);
            return (x + (show_sign == 1 ? 2 : 1) + (repet_c == '0' ? 1 : 0));
        }
    }
    return (1);
}

int    pre_parse(va_list ap, int i, char *str)
{
    char c = str[i + 1];
    return_func_t result;
    int x = 0;

    if (c == '%') {
        my_putchar(c);
        return (1);
    }
    result = run_func(c, ap);
    if (result.result == 1 && result.str != NULL)
        my_putstr(result.str);
    else if (result.result == 0) {
        x = parse(i, str, ap);
        if (x == 1) {
            my_putchar('%');
            my_putchar(c);
        }
        return (x);
    }
    return (1);
}

int    my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%')
            i += pre_parse(ap, i, str);
        else
            my_putchar(str[i]);
    }
    va_end(ap);
}