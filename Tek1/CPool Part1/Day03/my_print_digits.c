/*
** EPITECH PROJECT, 2019
** my_print_digits.c
** File description:
** display 0-9
*/

#include <unistd.h>

int my_print_digits(void)
{
    int number = 48;

    while (number <= 57 ){
        write(1, &number, 1);
        number = number + 1;
    }
    return 0;
}
