/*
** EPITECH PROJECT, 2020
** PSU_my_printf_2019
** File description:
** test
*/

#include "include/my.h"
#include <stdlib.h>

//gcc -o test test.c -L. -lmy

int main(int ac, char **av)
{
    // my_printf("%h");
    // my_printf("variable = %d\n", 2);


    // char **array = malloc(sizeof(char *) * 3);
    // array[0] = "Hello";
    // array[1] = "World";
    // array[2] = NULL;
    // my_printf("%a", array);
    // free(array);

    // int *tebo = malloc(sizeof(int) * 5);
    // tebo[0] = 2;
    // tebo[1] = 4;
    // tebo[2] = 6;
    // tebo[3] = 8;
    // tebo[4] = 0;
    // my_printf("%t", tebo);
    my_printf("%h");
    my_printf("Hello %r!", "World");
}