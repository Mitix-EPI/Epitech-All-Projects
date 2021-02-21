/*
** EPITECH PROJECT, 2020
** structures prototypes
** File description:
** structures for asm
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "op.h"

typedef struct label_s {
    char *label_name;
    int byte_position;
    struct label_s *next;
} label_t;

typedef struct line_s {
    char *type;
    int line;
    int nb_byte;
    char **arg;
} line_t;

typedef struct node_s {
    line_t line;
    struct node_s *next;
} node_t;


typedef struct asm_s {
    header_t header;
    node_t *head;
    label_t *label;
    int fd;
    char *good_path;
} asm_t;

#endif
