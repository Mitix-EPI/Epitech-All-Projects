/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** jobs
*/

#include "jobs/jobs.h"

void check_done(void)
{
    job_t *head = get_head();
    int status = 0;

    if (!*head)
        return;
    for (job_t job = *head; job; job = job->next) {
        if (waitpid(job->pid, &status, WNOHANG) == -1 && job->is_done == 0) {
            my_printf("[%d]  %c Done                          %s\n",
            job->pos, (job->next &&
            !job->next->is_done) ? '+' : '-', job->line);
            job->is_done = 1;
        }
    }
}

void control_job(shell_t *shell, pid_t process, int *status, char **argv)
{
    static int turn = 0;

    if (!shell->job_control)
        wait(status);
    else
        add_node(process, &turn, argv);
    shell->job_control = 0;
}