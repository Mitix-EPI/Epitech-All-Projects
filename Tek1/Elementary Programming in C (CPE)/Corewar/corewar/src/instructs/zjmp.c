/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** zjmp
*/

#include "corewar.h"

void zjmp_function(champions_t *champ, char *arena, int coding_byte)
{
    int arg = 0;

    champ->to_wait.nb_toexe = 0;
    champ->to_wait.ctw = 0;
    if (champ->carry == 1) {
        arg = give_int(arena, champ->pc + 1, 2);
        champ->pc += (arg % IDX_MOD);
    } else {
        champ->pc += 2;
    }
}
