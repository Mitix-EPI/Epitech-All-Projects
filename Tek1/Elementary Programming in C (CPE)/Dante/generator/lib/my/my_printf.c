/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"

static ptr_t tab[] =
{
    {'d', my_print_nbr},
    {'s', my_print_str},
    {'c', my_print_char},
    {'u', my_print_unsigned},
    {'o', my_print_octal},
    {'x', my_print_hexa},
    {'X', my_print_hexa_capitalize},
    {'i', my_print_nbr},
    {'p', my_print_pointer_adress},
    {'b', my_print_binary},
    {'S', my_print_show_char},
    {'e', my_print_error},
    {'E', my_print_nb_error},
    {'n', my_print_len}
};

char *my_get_size(char const *format)
{
    char *tempo;
    int i = 0;
    tempo = malloc(10);

    while (format[i] >= '0' && format[i] <= '9') {
        tempo[i] = format[i];
        i += 1;
    }
    return tempo;
}

int my_print_nicely(char const *format, va_list ap, int *n)
{
    int result;
    char *tempo;
    tempo = my_get_size(format);
    int i = my_strlen(tempo);
    char thing = ' ';

    if (tempo[0] == '0') {
        thing = '0';
    }
    result = my_getnbr(tempo);
    for (int icr = 0; icr < 14; icr += 1) {
        if (format[i] == tab[icr].c)
            tab[icr].ptr(ap, result, thing, n);
    }
    return (i);
}

len_t my_crossroad(char const *format, va_list ap, int i, len_t lenght)
{
    if (*(format + 1) >= '0' && *(format + 1) <= '9') {
        lenght.j = my_print_nicely(&format[1], ap, &lenght.n);
        i = 1;
    } else {
        for (int icr = 0; icr < 14; icr += 1) {
            if (*(format + 1) == tab[icr].c) {
                tab[icr].ptr(ap, 0, 'a', &lenght.n);
                i = 1;
                lenght.j = 0;
            }
        }
    }
    if (i == 0) {
        my_putchar('%');
        my_putchar(format[1]);
    }
    return (lenght);
}

int my_printf(char const *format, ...)
{
    len_t lenght = {0, 0};
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i += 1) {
        if (format[i] == '%' && format[i + 1] == '%'){
            i += 1;
            my_putchar('%');
        }
        else if (format[i] == '%' && format[i + 1] != '%'){
            lenght = my_crossroad(&format[i], ap, 0, lenght);
            i += lenght.j + 1;
        } else {
            my_putchar(format[i]);
            lenght.n += 1;
        }
    }
    va_end(ap);
    lenght.n -= 1;
    return (lenght.n);
}