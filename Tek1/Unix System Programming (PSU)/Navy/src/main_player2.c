/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** main_player2.c
*/

#include "../include/my.h"

int connection_player2(char **av)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\n");
    if (kill(my_getnbr(av[1]), SIGUSR1) < 0)
        return (1);
    signal(SIGUSR2, connection_validated);
    pause();
    return (0);
}

void fill_the_struct_1(struct sigaction *act)
{
    sigemptyset(&act->sa_mask);
    act->sa_sigaction = catch_siguser1;
    act->sa_flags = SA_SIGINFO;
}

char *translater(void)
{
    int i = 0;
    struct sigaction act;

    fill_the_struct_1(&act);
    for (; 1; i++) {
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        pause();
        if (data.catch_number == 12)
            break;
    }
    char letter = i + 'A' - 1;
    for (i = 0; 1; i++) {
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        pause();
        if (data.catch_number == 12)
            break;
    }
    return (build_coord(letter, i + '0'));
}

void send_hit_or_missed(char *coord)
{
    usleep(1000);
    if (check_if_it_touches_the_player(coord) == 1) {
        kill(data.pid, SIGUSR1);
    } else {
        kill(data.pid, SIGUSR2);
    }
}

int main_player_two(char **av)
{
    if (connection_player2(av))
        return (84);
    sets(av[2]);
    game_loop_player2();

    return (0);
}