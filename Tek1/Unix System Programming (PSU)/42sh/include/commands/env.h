/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Commands of minishell2
*/

#include "minishell2.h"

#ifndef CMD_ENV_H
#define CMD_ENV_H

int cmd_setenv(shell_t *shell, char **argv);
int cmd_unsetenv(shell_t *shell, char **argv);
int cmd_env(shell_t *shell, char **argv);
void update_path(shell_t *shell);

#endif