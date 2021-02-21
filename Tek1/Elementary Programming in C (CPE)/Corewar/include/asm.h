/*
** EPITECH PROJECT, 2020
** asm
** File description:
** prototypes of asm functions
*/

#ifndef ASM_H_
#define ASM_H_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void my_putstr(const int, char *);
int read_yolotron(char *);
void my_cutstr(char *);
int my_strlen(char *);
void analyse_command(char *);
int my_strcmp(char const *, char const *);
int my_isnum(char const *);
int my_atoi(const char *);
void my_put_nbr(int);
int add_values(char *, char *);
int remove_values(char *, char *);
void my_putstr(const int, char *);
int display(char *);
void my_putchar(const int, char);

#endif