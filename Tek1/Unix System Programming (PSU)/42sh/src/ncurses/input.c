/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input
*/

#include "ncurses/ncurses.h"
#include "ncurses/erase.h"

char *initialise_input(void)
{
    char *str = malloc(sizeof(char) * (1024 + 1));

    for (int i = 0; i <= 1024; i++)
        str[i] = 0;
    return (str);
}

void print_in_input(int c, char *input, int *i)
{
    for (int j = 1023; j + 1 > *i; j--)
        input[j + 1] = input[j];
    input[*i] = c;
    *i += 1;
    printf("\0338");
    printf("\033[0J");
    printf("\033[0K");
    printf("%s", input);
    for (int j = my_strlen(input) - *i, k = 0; k < j; k++)
        printf("\033[D");
}

void reset_input(char *input, char *tmp)
{
    int i = 0;

    for (; i <= 1024; i++)
        input[i] = 0;
    for (i = 0; tmp && tmp[i]; i++)
        input[i] = tmp[i];
}

char *copy_str_in_str(char *input, char *src)
{
    int len = my_strlen(src);
    int j = 0;

    for (j = 0; j <= 1024; j++)
        input[j] = 0;
    for (j = 0; j <= 1024 && j < len; j++) {
        input[j] = src[j];
    }
    return (input);
}

void exit_input(char *input, int *i)
{
    if (my_strlen(input) > 0) {
        remove_charac_behind(input, i);
    } else {
        my_putstr("exit\n");
        exit(0);
    }
}