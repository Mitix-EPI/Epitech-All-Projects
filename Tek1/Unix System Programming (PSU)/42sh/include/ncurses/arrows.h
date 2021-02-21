/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** arrows
*/

#ifndef ARROWS_H_
#define ARROWS_H_

#include "minishell2.h"

void arrow_up(shell_t *shell, char *input, int *i);
void arrow_down(shell_t *shell, char *input, int *i);
void arrows(int *i, int c, char *input, shell_t *shell);

#endif /* !ARROWS_H_ */
