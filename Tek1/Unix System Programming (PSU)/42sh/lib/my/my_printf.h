/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printf declarations
*/

#include "my.h"

#define ARRAY_SIZE 11

char *print_str(va_list);
char *print_char(va_list);
char *print_number(va_list);
char *print_wide_string(va_list);
char *print_pointer(va_list);
char *print_octal(va_list);
char *print_hexa(va_list);
char *print_unsigned(va_list);
char *print_upper_hexa(va_list);
char *print_binary(va_list);
void my_put_octal_number(int);
int number_to_octal(int);

typedef struct parser_s {
    char c;
    char *(*ptr)(va_list);
} parser_t;

typedef struct return_func {
    char *str;
    int result;
} return_func_t;

parser_t funcs[] = {
    {'b', print_binary},
    {'c', print_char},
    {'d', print_number},
    {'i', print_number},
    {'o', print_octal},
    {'p', print_pointer},
    {'s', print_str},
    {'S', print_wide_string},
    {'u', print_unsigned},
    {'x', print_hexa},
    {'X', print_upper_hexa},
};
