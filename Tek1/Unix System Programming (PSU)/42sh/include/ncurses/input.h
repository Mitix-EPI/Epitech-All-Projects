/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input
*/

#ifndef INPUT_H_
#define INPUT_H_

#include "minishell2.h"

char *initialise_input(void);
void print_in_input(int c, char *input, int *i);
void reset_input(char *input, char *tmp);
char *copy_str_in_str(char *input, char *src);
void exit_input(char *input, int *i);

#endif /* !INPUT_H_ */
