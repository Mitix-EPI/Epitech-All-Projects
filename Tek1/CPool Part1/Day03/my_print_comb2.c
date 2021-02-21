/*
** EPITECH PROJECT, 2019
** my_print_comb2.c
** File description:
** display 4 digits (differents)
*/

#include <unistd.h>

int verifi(char a, char b, char c, char d)
{
    int space = 32;
    int comma = 44;

    if ((c > a) || (c == a && d > b)){
            write(1, &a, 1);
            write(1, &b, 1);
            write(1, &space, 1);
            write(1, &c, 1);
            write(1, &d, 1);
            if (a == '9' && b == '8'){
            }
            else {
                write(1, &comma, 1);
                write(1, &space, 1);
            }
    }
    return 0;
}

int my_boucle(char a, char b, char c, char d)
{
    while (d <= '9'){
        verifi(a, b, c, d);
        d = d + 1;
    }
    return d;
}

int my_print_comb2(void)
{
    char a = '0';
    char b = '0';
    char c = '0';
    char d = '0';

    while (a <= '9'){
        while (b <= '9'){
            while (c <= '9'){
                my_boucle(a, b, c, d);
                d = '0';
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
