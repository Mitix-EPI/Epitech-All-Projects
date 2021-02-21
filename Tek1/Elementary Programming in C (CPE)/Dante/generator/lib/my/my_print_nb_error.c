/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_print_nb_error
*/

#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);

void my_error_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        write(2, &str[i], 1);
}

int my_put_nb_error(int nb)
{
    char c = 0;

    if (nb == -2147483648)
        my_error_str("-2147483648\0");
    if (nb < 0 && nb != -2147483648) {
        write(2, "-", 1);
        nb = -1 * nb;
    }
    if (nb >= 10) {
        my_put_nb_error(nb / 10);
        c = nb % 10 + '0';
        write(2, &c, 1);
    }
    else if (nb != -2147483648) {
        c = nb + '0';
        write(2, &c, 1);
    }
    return (0);
}

void my_print_nb_error(va_list ap, int test, char thing, int *n)
{
    int result;
    int tempo;
    int len = 0;

    result = va_arg(ap, int);
    tempo = result;
    while (tempo > 0) {
        tempo = tempo / 10;
        len += 1;
    }
    *n += len;
    for (int i = 0; i + len < test; i += 1) {
        write(2, &thing, 1);
    }
    my_put_nb_error(result);
}