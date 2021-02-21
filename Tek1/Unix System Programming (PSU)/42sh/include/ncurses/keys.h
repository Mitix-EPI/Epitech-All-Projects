/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** keys
*/

#ifndef KEYS_H_
#define KEYS_H_

#include "minishell2.h"

int other_other_keys(void);
void key_delete(char *input, int *i);
void other_keys(char *input, int *i, shell_t *shell);
void check_ctrls(char c, char *input, int *i);

#endif /* !KEYS_H_ */
