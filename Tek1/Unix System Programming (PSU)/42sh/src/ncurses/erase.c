/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** erase
*/

#include "minishell2.h"
#include "ncurses/ncurses.h"
#include "ncurses/input.h"

void erase_before_cursor(char *input, int *i)
{
    input = copy_str_in_str(input, my_strdup(&input[*i]));
    *i = 0;
    printf("\0338");
    printf("\033[0J");
    printf("\033[0K");
    printf("%s", input);
    for (int j = my_strlen(input) - *i, k = 0; k < j; k++)
        printf("\033[D");
}

void erase_after_cursor(char *input, int *i)
{
    for (int j = *i; j <= 1024; j++)
        input[j] = 0;
    printf("\0338");
    printf("\033[0J");
    printf("\033[0K");
    printf("%s", input);
}

void remove_charac_behind(char *input, int *i)
{
    if (*i >= 0) {
        for (int j = *i; j < 1024; j++)
            input[j] = input[j + 1];
        printf("\0338");
        printf("\033[0J");
        printf("\033[0K");
        printf("%s", input);
        for (int j = my_strlen(input) - *i, k = 0; k < j; k++)
            printf("\033[D");
    }
}

void remove_charac_input(char *input, int *i)
{
    if (*i) {
        for (int j = *i - 1; j < 1024; j++)
            input[j] = input[j + 1];
        *i -= 1;
        printf("\0338");
        printf("\033[0J");
        printf("\033[0K");
        printf("%s", input);
        for (int j = my_strlen(input) - *i, k = 0; k < j; k++) {
            printf("\033[D");
        }
    }
}
