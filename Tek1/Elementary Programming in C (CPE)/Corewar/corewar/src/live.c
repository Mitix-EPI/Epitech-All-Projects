/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** live
*/

#include "corewar.h"

void reset_live(core_t *core)
{
    for (int i = 0; i < core->nb_champs; i += 1) {
        // dprintf(2, "%s live = %d\n", core->champs[i].header.prog_name, core->champs[i].live);
        if (core->champs[i].live == 0) {
            exit (84);
            core->champs[i].status = 0;
            dprintf(2, "%s is dead\n", core->champs[i].header.prog_name);
        }
        core->champs[i].live = 0;
    }
}

void print_name(champions_t *champ)
{
    my_putstr(2, "Champion:");
    my_putstr(2, champ->header.prog_name);
    my_putstr(2, " is alived\n");
}

void live_function(core_t *core, char *arena, int pc, int i)
{
    int nb = give_int(arena, pc + 1, 4);

    dprintf(2, "je suis passé\n");
    core->champs[i].to_wait.nb_toexe = 0;
    core->champs[i].to_wait.ctw = 0;
    if (nb == core->champs[i].id) {
        print_name(&core->champs[i]);
        core->champs[i].live = 1;
        core->nb_live += 1;
    }
    core->champs[i].pc += 3;
}