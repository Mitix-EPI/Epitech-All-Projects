/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"

#ifndef INITIALIZATION_H
#define INITIALIZATION_H

int initialize(char **, int);
void check_filerc_exist(void);
void init_shell_var(shell_t *shell);
void init_history_rc(shell_t *shell);

#endif