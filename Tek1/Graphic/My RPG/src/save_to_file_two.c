/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

void my_putchar2(char c, int fd)
{
    write(fd, &c, 1);
}

void put_in_file(int nb, int fd)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar2('-', fd);
    }
    if (nb >= 10)
        put_in_file(nb / 10, fd);
    nb = nb % 10;
    my_putchar2(nb + 48, fd);
}

void put_in_file_with_write(int nb, int fd)
{
    put_in_file(nb, fd);
    write(fd, ":", 1);
}

int save_to_file_three(rpg_t *rpg, int fd)
{
    char *str = NULL;

    str = ftoa(rpg->fight->enns[0].velocity, 2);
    write(fd, str, my_strlen(str));
    free(str);
    write(fd, ":", 1);
    put_in_file_with_write(rpg->fight->nb_enn, fd);
    for (int i = 0; i < rpg->fight->nb_enn; i += 1) {
        put_in_file_with_write(rpg->fight->enns[i].life, fd);
        put_in_file_with_write(rpg->fight->enns[i].pos.x, fd);
        put_in_file_with_write(rpg->fight->enns[i].pos.y, fd);
        put_in_file_with_write(rpg->fight->enns[i].tmp, fd);
    }
    rpg->save = 0;
    return (0);
}