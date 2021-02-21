/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** return value
*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int n = 0;
    char enter = '\n';

    while (i < argc){
        n = 0;
        while (argv[i][n] != '\0'){
            write(1, &argv[i][n], 1);
            n++;
        }
        write(1, &enter, 1);
        i++;
    }
    return (0);
}
