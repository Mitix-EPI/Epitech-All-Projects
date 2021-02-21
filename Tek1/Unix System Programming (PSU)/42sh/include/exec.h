/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"

#ifndef EXEC_H
#define EXEC_H

char *get_binary_name(shell_t *, char *);
int exec_binary(shell_t *, char *, char **, int[2]);
void control_job(shell_t *, pid_t, int *, char **);

#endif
