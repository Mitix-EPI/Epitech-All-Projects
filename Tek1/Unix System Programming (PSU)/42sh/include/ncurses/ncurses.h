/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** test
*/

#ifndef NCURSES_H_
#define NCURSES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <ncurses.h>
#include <curses.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#include "minishell2.h"
#include "history/move_inside_linked_list.h"

#define cursorforward(x) printf("\033[%dC", (x))
#define cursorbackward(x) printf("\033[%dD", (x))

#define ESC          27
#define INSERT       50
#define DELETE       51
#define PGUP         53
#define PGDN         54
#define ARROWUP      65
#define ARROWDOWN    66
#define ARROWRIGHT   67
#define ARROWLEFT    68
#define END          70
#define HOME         72
#define OTHER        79
#define BRACKETLEFT  91
#define TILDE       126
#define BACKSPACE   127

#define CTRL_KEYPRESS(k)  ((k)   & 0x1f)

#define STDIN           0
#define SIZE         1024

char *ncurse(shell_t *shell);

typedef struct saved_s {
    int **ctrl_c;
} saved_t;

#endif /* !NCURSES_H_ */
