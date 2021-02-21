/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** start
*/

#include "../include/my.h"

void cd_home(objt_struct_t **head)
{
    char *tmp = return_str("HOME", *head);

    if (tmp)
        chdir(tmp);
}

void siginhandler(int sig_num)
{
    char *str = malloc(sizeof(char) * 4096);

    if (sig_num != 666)
        my_putstr("\n");
    getcwd(str, 4096);
    my_putstr(str);
    my_putstr(" > ");
    free(str);
}

void print_errors(int stat)
{
    char *sig = strsignal(WTERMSIG(stat));

    if (my_strcmp(sig, "Floating point exception") == 0)
        my_putstr("Floating exception\n");
    else if (__WCOREDUMP(stat))
        my_putstr("Segmentation fault (core dump)\n");
    else {
        my_putstr(sig);
        my_putstr("\n");
    }
}
