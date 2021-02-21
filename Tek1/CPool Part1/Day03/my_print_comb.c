/*
** EPITECH PROJECT, 2019
** my_print.comb.c
** File description:
** display tree digits (differents)
*/

#include <unistd.h>

int my_print(char a, char b, char c)
{
    int comma = 44;
    int space = 32;

    if (a < b && b < c){
        write(1, &a, 1);
        write(1, &b, 1);
        write(1, &c, 1);
        if (a != '7' || b != '8' || c != '9'){
            write(1, &comma, 1);
            write(1, &space, 1);
        }
    }
    return 0;
}

int my_print_comb(void)
{
    char a = '0';
    char b = '0';
    char c = '0';

    while  (a <= '9'){
        while (b <= '9'){
            while (c <= '9'){
                my_print(a, b, c);
                c = c + 1;
            }
            c = '0';
            b = b + 1;
        }
        b = '0';
        a = a + 1;
    }
    return 0;
}
