/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Header of minishell2
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <getopt.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <error.h>
#include "my.h"

#ifndef SHELL_H
#define SHELL_H

#define STRTOWA my_str_to_word_array

typedef struct history_s {
    char *command;
    struct history_s *next;
    struct history_s *previous;
} history_t;

typedef struct alias_s {
    char *name;
    char *command;
    struct alias_s *next;
    struct alias_s *previous;
} alias_t;

typedef struct env_s {
    char *var;
    char *value;
    struct env_s *next;
    struct env_s *prec;
} env_t;

typedef struct var_s {
    char *var;
    char *value;
    struct var_s *next;
    struct var_s *prec;
} var_t;

typedef struct shell_s {
    var_t *first_var;
    var_t *last_var;
    env_t *first_env;
    env_t *last_env;
    history_t *history;
    history_t *cur_history;
    alias_t *alias;
    char *path;
    int job_control;
    int last_exit_code;
    int h_index;
    char *history_path;
    char *path_rc;
    int *ctrl_c;
} shell_t;

#endif