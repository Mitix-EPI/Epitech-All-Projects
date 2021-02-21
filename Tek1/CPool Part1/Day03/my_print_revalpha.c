/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:
** display z-a
*/

#include <unistd.h>

int my_print_revalpha(void)
{
    int z = 122;

    while (z >= 97){
        write (1, &z, 1);
        z = z - 1;
    }
    return 0;
}
