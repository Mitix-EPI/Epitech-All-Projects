/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Commands of minishell2
*/

#include "minishell2.h"

#ifndef ALIAS_H
#define ALIAS_H

int cmd_alias(shell_t *shell, char **argv);
int cmd_unalias(shell_t *shell, char **argv);

#endif