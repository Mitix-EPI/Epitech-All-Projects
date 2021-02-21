/*
** EPITECH PROJECT, 2020
** asm
** File description:
** main header for asm
*/

#ifndef ASM_H_
#define ASM_H_

/*
(f)open
read
write
getline
lseek
fseek
(f)close
malloc
my_realloc
free
exit
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NOT_NAME_FIRST     80
#define MISSING_QUOTES     81
#define NAME_TOO_LONG      82
#define NOT_COMMENT_SECOND  83
#define COMMENT_TOO_LONG   84
#define NOT_EXISTING_COMMENT  85
#define INCORRECT_LABEL_NAME  86
#define WRONG_VARIABLE_TYPE  87
#define NOT_ENOUGH_ARGUMENTS  88
#define WRONG_INSTRUCTION  89
#define LABEL_NOT_EXIST  90
#define NOT_EXISTING_NAME 91

#include "struct.h"
#include "functions.h"
#include "op.h"

#endif
