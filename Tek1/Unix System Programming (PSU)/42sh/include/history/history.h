/*
** EPITECH PROJECT, 2020
** history.h
** File description:
** history.h
*/

#include "minishell2.h"
#include <fcntl.h>

#ifndef HISTORY_H_
#define HISTORY_H_

void history(char *command, shell_t *shell);
void check_history_file_exist(shell_t *shell);
void add_node_at_back(char *command, history_t **node);
void add_node_at_front(char *command, history_t **node);
int is_historyable(char *command);

#endif /* !HISTORY_H_ */
