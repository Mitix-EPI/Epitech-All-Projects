/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Cmd of minishell2
*/

#include "minishell2.h"

void    cmd_exit(shell_t *shell, char **argv)
{
    (void)shell;
    if (argv[0] && my_str_isnum(argv[0]))
        exit(my_getnbr(argv[0]));
    else
        exit(0);
    return;
}