/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** handling_pcs
*/

#include "corewar.h"

int give_int(char *arena, int pc, int size)
{
    int nb = 0;

    for (int i = 0; i < size; i += 1) {
        nb = nb << 8;
        nb += arena[pc % MEM_SIZE];
        pc += 1;
    }
    return (nb);
}

void handling_pc(champions_t *champ, char *arena)
{
    if (arena[champ->pc] == 0x02) {
        ld_function(champ, arena, arena[champ->pc + 1]);
        return;
    }
    if (arena[champ->pc] == 0x03) {
        st_function(champ, arena, arena[champ->pc + 1]);
        return;
    }
    if (arena[champ->pc] == 0x04) {
        add_function(champ, arena, arena[champ->pc + 1]);
        return;
    }
    if (arena[champ->pc] == 0x05) {
        sub_function(champ, arena, arena[champ->pc + 1]);
        return;
    }
    return;
}

void handling_pcs(core_t *core)
{
    for (int i = 0; i < core->nb_champs; i++) {
        if (core->champs[i].wait <= 0) {
            handling_pc(&core->champs[i], core->arena);
        }
    }
}
