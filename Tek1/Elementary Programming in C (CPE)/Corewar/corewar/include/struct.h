/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "op.h"

typedef struct wait_s {
    int ctw;
    int nb_toexe;
} wait_t;

typedef struct champions_s{
    header_t header;
    char *instructs;
    int pc;
    int reg[16];
    int wait;
    char *path;
    int id;
    int status;
    int live;
    int carry;
    wait_t to_wait;
} champions_t;

typedef struct core_s {
    char *arena;
    char *color_txt;
    int nb_champs;
    int ctd;
    int nb_live;
    int dump;
    int dump_nbr;
    champions_t *champs;
} core_t;

#endif /* !STRUCT_H_ */
