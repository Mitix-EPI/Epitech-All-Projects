/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NOT_GOOD_EXTENSION    80
#define NOT_ENOUGHT_CHAMPS    81
#define CANT_OPEN_FILE        82
#define CANT_READ_HEADER      83
#define CANT_READ_INSTRUCT    84

#define PC_PLAYER1             1
#define PC_PLAYER2             2
#define PC_PLAYER3             3
#define PC_PLAYER4             4

#define INST_PLAYER1             5
#define INST_PLAYER2             6
#define INST_PLAYER3             7
#define INST_PLAYER4             8

#include "struct.h"
#include "functions.h"
#include "op.h"

#endif /* !COREWAR_H_ */
