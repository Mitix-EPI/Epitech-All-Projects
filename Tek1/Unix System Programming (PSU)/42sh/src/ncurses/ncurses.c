/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** test
*/

#include "minishell2.h"
#include "history/history.h"
#include "history/move_inside_linked_list.h"
#include "ncurses/ncurses.h"
#include "prompt.h"
#include "ncurses/input.h"
#include "ncurses/keys.h"
#include "ncurses/erase.h"

void siginhandler(int sig_num, void *ctrl_c)
{
    static saved_t saved_ctrlc = (saved_t){NULL};

    if (saved_ctrlc.ctrl_c == NULL) {
        saved_ctrlc.ctrl_c = ctrl_c;
        return;
    }
    if (sig_num != 666) {
        *(*(saved_ctrlc.ctrl_c)) = 1;
        my_putstr("\n");
    }
    return;
}

void init_editor(struct termios *terms, shell_t *shell)
{
    signal(SIGINT, (void (*)(int))siginhandler);
    shell->ctrl_c = malloc(sizeof(int));
    *(shell->ctrl_c) = 0;
    siginhandler(666, &(shell->ctrl_c));
    tcgetattr(0, &terms[1]);
    memcpy(&terms[0], &terms[1], sizeof(terms[0]));
    terms[0].c_lflag &= ~( ICANON | ECHO );
    terms[0].c_cc[VMIN] = 0;
    terms[0].c_cc[VTIME] = 1;
    tcsetattr(0, TCSANOW, &terms[0]);
    terms[0] = terms[1];
    setbuf(stdin, NULL);
    disp_prompt();
    printf("\0337");
}

void check_active_ctrl_c(shell_t *shell, char *input, int *i)
{
    if (*(shell->ctrl_c) == 1) {
        disp_prompt();
        for (int j = 0; j <= 1024; j++)
            input[j] = 0;
        *i = 0;
        printf("\0337");
        *(shell->ctrl_c) = 0;
    }
}

char *ncurse(shell_t *shell)
{
    struct termios *terms = (struct termios *) malloc(sizeof(*terms) * 2);
    char *input = initialise_input();

    init_editor(terms, shell);
    for (int c = 0, i = 0; c != '\n'; c = getchar()) {
        check_active_ctrl_c(shell, input, &i);
        if (isprint(c)) {
            print_in_input(c, input, &i);
            continue;
        }
        check_ctrls(c, input, &i);
        if (c == BACKSPACE)
            remove_charac_input(input, &i);
        if (c == ESC)
            other_keys(input, &i, shell);
    }
    printf("\n");
    return (input);
}
