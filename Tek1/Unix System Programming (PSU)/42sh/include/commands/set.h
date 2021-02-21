/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Commands of minishell2
*/

#include "minishell2.h"

#ifndef CMD_SET_H
#define CMD_SET_H

int cmd_set(shell_t *shell, char **argv);
int cmd_unset(shell_t *shell, char **argv);

#endif