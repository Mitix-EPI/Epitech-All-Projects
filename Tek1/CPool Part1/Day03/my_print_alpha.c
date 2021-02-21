/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** display a-z
*/

#include <unistd.h>

int my_print_alpha(void)
{
    int a = 97;

    while (a <= 122){
        write (1, &a, 1);
        a = a + 1;
    }
    return 0;
}
