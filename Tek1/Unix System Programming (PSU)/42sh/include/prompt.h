/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include "minishell2.h"

#ifndef PROMPT_H
#define PROMPT_H

void read_input(shell_t *, int);
void disp_error(char *, int);
void disp_prompt(void);

#endif