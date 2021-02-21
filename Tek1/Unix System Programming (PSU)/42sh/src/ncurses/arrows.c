/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** arrows
*/

#include "minishell2.h"
#include "ncurses/ncurses.h"
#include "ncurses/input.h"
#include "ncurses/cursor.h"

void arrow_up(shell_t *shell, char *input, int *i)
{
    char *tmp = NULL;

    tmp = get_history_previous(shell);
    if (tmp != NULL) {
        printf("\0338");
        printf("\033[0J");
        printf("\033[0K");
        printf("%s", tmp);
        reset_input(input, tmp);
        *i = my_strlen(input);
    } else
        cursor_end(i, input);
}

void arrow_down(shell_t *shell, char *input, int *i)
{
    char *tmp = NULL;

    tmp = get_history_next(shell);
    if (tmp != NULL) {
        printf("\0338");
        printf("\033[0J");
        printf("\033[0K");
        printf("%s", tmp);
        reset_input(input, tmp);
        *i = my_strlen(input);
    }
}

void arrows(int *i, int c, char *input, shell_t *shell)
{
    if (c == ARROWLEFT && *i > 0) {
        *i -= 1;
        printf("\033[D");
    }
    if (c == ARROWRIGHT && *i < my_strlen(input)) {
        *i += 1;
        printf("\033[C");
    }
    if (c == ARROWUP) {
        arrow_up(shell, input, i);
    }
    if (c == ARROWDOWN) {
        arrow_down(shell, input, i);
    }
}