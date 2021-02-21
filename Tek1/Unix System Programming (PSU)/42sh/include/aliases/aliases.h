/*
** EPITECH PROJECT, 2020
** aliases.h
** File description:
** aliases.h
*/

#include "minishell2.h"

#ifndef ALIASES_H_
#define ALIASES_H_

void add_alias(char *command, char *name, alias_t **node);
void unset_alias(shell_t *shell, char *name);
void check_filerc_exist(void);
char *proceed_alias(shell_t *shell, char *arr_command);
void    display_aliases(shell_t *shell);

#endif /* !ALIASES_H_ */
