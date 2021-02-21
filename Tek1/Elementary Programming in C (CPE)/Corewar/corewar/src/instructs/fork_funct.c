/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fork_funct
*/

#include "../../include/corewar.h"

void reac_champs(core_t *core, champions_t champ)
{
    int nb = 0;

    core->champs = realloc(core->champs, (core->nb_champs + 1) * sizeof(champions_t));
    if (!core->champs) {
        perror("realloc");
        exit (84);
    }
    core->champs[core->nb_champs] = champ;
    core->nb_champs += 1;
}

void fork_function(core_t *core, int i, char *arena, int pc)
{
    int nb = give_int(arena, pc + 1, 2);
    champions_t champs;

    core->champs[i].to_wait.nb_toexe = 0;
    core->champs[i].to_wait.ctw = 0;
    champs.header = core->champs[i].header;
    champs.instructs = core->champs[i].instructs;
    champs.pc = core->champs[i].pc + (nb % IDX_MOD);
    for (int j = 0; j < REG_NUMBER; j += 1)
        champs.reg[j] = core->champs[i].reg[j];
    champs.wait = core->champs[i].wait;
    champs.path = core->champs[i].path;
    champs.id = core->champs[i].id;
    champs.status = core->champs[i].status;
    champs.live = core->champs[i].live;
    champs.carry = core->champs[i].carry;
    champs.to_wait.nb_toexe = 0;
    champs.to_wait.ctw = 0;
    reac_champs(core, champs);
    core->champs[i].pc += 2;
}
