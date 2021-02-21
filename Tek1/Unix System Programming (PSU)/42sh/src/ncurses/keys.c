/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** keys
*/

#include "ncurses/ncurses.h"
#include "ncurses/erase.h"
#include "ncurses/cursor.h"
#include "ncurses/arrows.h"
#include "ncurses/input.h"
#include "prompt.h"

int other_other_keys(void)
{
    int c = getchar();

    if (c == HOME)
        c = getchar();
    if (c == END)
        c = getchar();
    return (c);
}

void key_delete(char *input, int *i)
{
    int c = getchar();

    if (c == TILDE)
        remove_charac_behind(input, i);
}

void other_keys(char *input, int *i, shell_t *shell)
{
    int c = getchar();

    if (c == OTHER)
        c = other_other_keys();
    if (c == BRACKETLEFT) {
        c = getchar();
        if (c == HOME)
            cursor_home(i);
        if (c == END)
            cursor_end(i, input);
        if (c == DELETE)
            key_delete(input, i);
        arrows(i, c, input, shell);
    } else {
        ungetc(c, stdin);
    }
}

void check_ctrls(char c, char *input, int *i)
{
    if (c == CTRL_KEYPRESS('a'))
        cursor_home(i);
    if (c == CTRL_KEYPRESS('e'))
        cursor_end(i, input);
    if (c == CTRL_KEYPRESS('d'))
        exit_input(input, i);
    if (c == CTRL_KEYPRESS('u'))
        erase_before_cursor(input, i);
    if (c == CTRL_KEYPRESS('k'))
        erase_after_cursor(input, i);
    if (c == CTRL_KEYPRESS('l')) {
        system("clear");
        disp_prompt();
        for (int j = 0; j <= 1024; j++)
            input[j] = 0;
        *i = 0;
        printf("\0337");
    }
}