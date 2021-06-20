/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD09-alexandre.juan
** File description:
** ex00
*/

#ifndef EX00_H_
#define EX00_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

// Ctrhulhu
cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *);
void sleeping(cthulhu_t *);
void attack(cthulhu_t *);

// Koala
koala_t *new_koala(char *name, char is_a_legend);
void eat(koala_t *);

// initializer
static void cthulhu_initializer(cthulhu_t *);
static void koala_initializer(koala_t *, char *_name, char _is_A_Legend);

#endif /* !EX00_H_ */
