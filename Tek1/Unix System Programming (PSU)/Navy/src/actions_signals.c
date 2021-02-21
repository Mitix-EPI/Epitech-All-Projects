/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** actions_signals
*/

#include "../include/my.h"

void connection_ennemy_validated(int sig, siginfo_t *siginfo, void *context)
{
    my_putstr("enemy connected\n");
    data.pid = (long)siginfo->si_pid;
    data.catch_number = siginfo->si_signo;
}

void catch_siguser1(int sig, siginfo_t *siginfo, void *context)
{
    data.pid = (long)siginfo->si_pid;
    data.catch_number = siginfo->si_signo;
}

void catch_siguser2(int sig, siginfo_t *siginfo, void *context)
{
    data.pid = (long)siginfo->si_pid;
    data.catch_number = (long)siginfo->si_signo;
}

void connection_validated(int sig)
{
    my_putstr("successfully connected\n");
}