/*
** EPITECH PROJECT, 2019
** my_int_to_str.c
** File description:
** return str from int
*/

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

char *my_revstr(char *str);

int get_int_len(int value)
{
    int l = 1;

    while (value > 9) {
        l++;
        value /= 10;
    }
    return (l);
}

char *my_itoa(int i)
{
    char *b = malloc (sizeof(char) * get_int_len(i) + 1);
    char const digit[] = "0123456789";
    char *p = b;
    int shifter;

    if (i < 0) {
        *p++ = '-';
        i *= -1;
    }
    shifter = i;
    do {
        ++p;
        shifter = shifter / 10;
    } while (shifter);
    *p = '\0';
    do {
        *--p = digit[i%10];
        i = i / 10;
    } while (i);
    return (b);
    free(b);
}