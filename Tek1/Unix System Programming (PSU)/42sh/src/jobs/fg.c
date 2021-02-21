/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** fg
*/

#include "jobs/fg.h"

int fg_vanilla(job_t *head)
{
    for (job_t cp = *head; cp; cp = cp->next) {
        if (cp->is_done == 0) {
            my_printf("%s\n", cp->line);
            waitpid(cp->pid, NULL, 0);
            cp->is_done = 1;
            return (0);
        }
    }
    return (1);
}

int get_by_number(int turn, job_t *head)
{
    pid_t to_wait = -15;
    job_t job = NULL;

    for (job_t cp = *head; cp; cp = cp->next) {
        if (cp->is_done == 0 && cp->pos == turn) {
            to_wait = (to_wait == -15) ? cp->pid : -16;
            job = cp;
        }
    }
    if (to_wait < 0) {
        my_printf("fg: %s.\n", (to_wait == -15) ? "No such job" :
        "Ambiguous");
        return (1);
    }
    my_printf("%s\n", job->line);
    job->is_done = 1;
    waitpid(to_wait, NULL, 0);
    return (0);
}

int get_by_string(job_t *head, char *str, int test)
{
    pid_t w = -15;
    job_t job = NULL;

    for (job_t cp = *head; cp; cp = cp->next) {
        if (cp->is_done == 0 && test == 0 && my_strstr(cp->line, str)) {
            w = (w == -15) ? cp->pid : -16;
            job = cp;
        } else if (cp->is_done == 0 && test == 1 &&
        my_strcmp(my_str_to_word_array(cp->line)[0], str) == 0) {
            w = (w == -15) ? cp->pid : -16;
            job = cp;
        }
    }
    if (w < 0) {
        my_printf("fg: %s.\n", (w == -15) ? "No such job" : "Ambiguous");
        return (1);
    }
    job->is_done = 1;
    my_printf("%s\n", job->line);
    waitpid(w, NULL, 0);
    return (0);
}

int fg_args(job_t *head, char **argv)
{
    job_t tmp = (*head) ? (*head)->next : NULL;
    int turn = -15;

    if (my_strlen(argv[0]) < 2)
        return (fg_vanilla(head));
    if (my_str_isnum(&argv[0][1]) && argv[0][1] != '-') {
        turn = my_getnbr(&argv[0][1]);
        return (get_by_number(turn, head));
    }
    if (argv[0][1] == '?')
        return (get_by_string(head, &argv[0][2], 0));
    if (argv[0][1] == '%' || argv[0][1] == '+')
        return (fg_vanilla(head));
    if (argv[0][1] == '-') {
        if (!tmp) {
            my_printf("fg: no previous job.\n");
            return (1);
        }
        return (fg_vanilla(&tmp));
    }
    return (get_by_string(head, &argv[0][1], 1));
}

int cmd_fg(shell_t *shell __attribute__((unused)), char **argv)
{
    job_t *head = get_head();
    int is_done = 0;

    for (job_t tmp = *head; tmp; tmp = tmp->next)
        is_done += !tmp->is_done;
    if (!is_done && !argv[0]) {
        my_printf("fg: no current job.\n");
        return (1);
    }
    if (argv[0] == NULL || **argv != '%')
        return (fg_vanilla(head));
    if (head)
        return (fg_args(head, argv));
    my_printf("fg: no current job.\n");
    return (1);
}

