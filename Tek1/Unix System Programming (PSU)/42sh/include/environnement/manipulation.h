/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"

#ifndef ENV_MANIPULATION_H
#define ENV_MANIPULATION_H

env_t  *getenv_var(shell_t *shell, char *var);
char  **getenv_arr(shell_t *shell);
void  add_env_node(shell_t *shell, env_t *new_env);
void  setenv_var(shell_t *shell, char *var, char *value);
void  unsetenv_var(shell_t *shell, char *var);

#endif