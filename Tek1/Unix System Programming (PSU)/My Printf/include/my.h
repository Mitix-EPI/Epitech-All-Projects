/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
typedef struct array_s
{
    char c;
    void(*ptr)();
}array_t;

void my_putchar(char const c);

int my_printf(char const *format, ...);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_put_nbr_base(long long nb, char *base);

int check_if_h(char const *str);

int unsignednbr(unsigned int nb);

void my_print_color(int color);


void is_str(va_list ap);

void is_nbr(va_list ap);

void is_ptr(va_list ap);

void is_char(va_list ap);

void is_hex(va_list ap);

void is_hex_maj(va_list ap);

void is_bin(va_list ap);

void is_oct(va_list ap);

void is_notneg(va_list ap);

void is_percentage(va_list ap);

void is_array(va_list ap);

void is_int_star(va_list ap);

void is_raimbow_str(va_list ap);

#endif /* !MY_H_ */

