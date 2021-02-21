/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** jobs
*/

#ifndef JOBS_H_
#define JOBS_H_

#include "minishell2.h"

typedef struct job_node_s
{
    pid_t pid;
    int pos;
    int is_done;
    char *line;
    struct job_node_s *next;
    struct job_node_s *prev;
} job_node_t;

typedef job_node_t * job_t;

job_t *get_head(void);
void add_node(pid_t, int *, char **);

#endif /* !JOBS_H_ */