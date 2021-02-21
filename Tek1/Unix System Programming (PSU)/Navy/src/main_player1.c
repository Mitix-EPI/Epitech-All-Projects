/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** main_player1.c
*/

#include "../include/my.h"

int check_touch(char *str)
{
    str[2] = 0;
    my_putstr("\n");
    my_putstr(str);
    my_putstr(": ");
    if (check_if_it_touches_the_player(str) == 1) {
        my_putstr("hit\n");
        return (1);
    } else {
        my_putstr("missed\n");
        return (0);
    }
}

int receive_hit_missed(char *str)
{
    struct sigaction act;

    fill_the_struct_1(&act);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    pause();
    str[2] = 0;
    my_putstr(str);
    my_putstr(": ");
    if (data.catch_number == 10) {
        my_putstr("hit\n");
        return (1);
    } else {
        my_putstr("missed\n");
        return (0);
    }
}

void connection_player1(void)
{
    struct sigaction act;

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\nwaiting for enemy connection...\n\n");
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = connection_ennemy_validated;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &act, NULL) < 0)
        my_putstr("ERROR\n");
    pause();
    kill(data.pid, SIGUSR2);
    usleep(1000);
}

void sets(char *path)
{
    int fd = open(path, O_RDONLY);
    char *file = malloc(sizeof(char) * (1024 + 1));
    int rd = read(fd, file, 1024);

    file[rd] = 0;
    data.board = create_fill_map(path);
    data.enn_board = create_empty_map();
    data.pos_map = open_pos(file);
    close(fd);
    free(file);
}

int main_player_one(char **av)
{
    connection_player1();
    sets(av[1]);
    game_loop_player1();
    return (0);
}