/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_print
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>

typedef struct ptr_s
{
    char c;
    void (*ptr)(va_list, int, char, int *);
} ptr_t;

typedef struct len_s
{
    int j;
    int n;
} len_t;

#include "my.h"

#endif /* my_printf_H_ */