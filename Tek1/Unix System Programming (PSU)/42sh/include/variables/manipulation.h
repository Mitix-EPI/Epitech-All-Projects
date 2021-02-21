/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"

#ifndef ENV_MANIPULATION_VAR_H
#define ENV_MANIPULATION_VAR_H

var_t *get_var(shell_t *shell, char *var);
char **get_arr(shell_t *shell);
void set_var(shell_t *shell, char *var, char *value);
void unset_var(shell_t *shell, char *var);
char *replace_vars(shell_t *shell, char *command);
int check_undefined_vars(shell_t *shell, char *command);

#endif