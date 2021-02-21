/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"
#include <glob.h>

#ifndef GLOB_H
#define GLOB_H

char **proceed_globbing(shell_t *shell, char **command);

#endif