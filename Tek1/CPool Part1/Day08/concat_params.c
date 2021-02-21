/*
** EPITECH PROJECT, 2019
** concat_params.c
** File description:
** return value
*/

#include <stdlib.h>
#include <unistd.h>

int count_my_all_charac(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int res;

    while (i < argc) {
        j = 0;
        while (argv[i][j] != '\0') {
            j++;
            res++;
        }
        i++;
    }
    res = res + argc;
    return (res);
}

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int u = 0;
    char *str;

    str = malloc(sizeof(char) * (count_my_all_charac(argc, argv)));
    while (i < argc) {
        j = 0;
        while (argv[i][j] != '\0') {
            str[u] = argv[i][j];
            j++;
            u++;
        }
        str[u] = '\n';
        u++;
        i++;
    }
    str[u] = '\0';
    return (str);
}
