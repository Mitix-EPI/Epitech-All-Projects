/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <limits.h>

typedef enum __attribute__((packed)) {
    FALSE,
    TRUE,
} bool;

typedef struct node_s node_t;

typedef struct link_s {
    node_t *node;
    struct link_s *next;
} link_t;

typedef struct node_s {
    char *name;
    int id;
    int distance;
    link_t *list;
} node_t;

typedef struct ants_s {
    int id;
    int moved;
} ants_t;

typedef struct paths_s {
    int ants_number;
    int nb_rooms;
    char *start;
    char *end;
    char **nodes;
    char **links;
    char **debug;
} paths_t;

#include "functions.h"

#endif /* !LEMIN_H_ */