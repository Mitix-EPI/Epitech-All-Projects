/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** handling_pcs
*/

#include "../include/corewar.h"

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

int handling_pc_three(char *arena, core_t *core, int i)
{
    if (core->champs[i].to_wait.nb_toexe == 0x09) {
        dprintf(2, "zjmp\n");
        zjmp_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    dprintf(2, "NUMBER : %d\n", core->champs[i].to_wait.nb_toexe);
    if (core->champs[i].to_wait.nb_toexe == 0x0a) {
        ldi_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    if (core->champs[i].to_wait.nb_toexe == 0x0d) {
        lld_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    return (0);
}

int handling_pc_two(char *arena, core_t *core, int i)
{
    if (core->champs[i].to_wait.nb_toexe == 0x05) {
        dprintf(2, "sub\n");
        sub_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    if (core->champs[i].to_wait.nb_toexe == 0x06) {
        dprintf(2, "and\n");
        dprintf(2, "On est bien sur du 'and'\n");
        and_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    if (core->champs[i].to_wait.nb_toexe == 0x07) {
        dprintf(2, "or\n");
        or_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    if (core->champs[i].to_wait.nb_toexe == 0x08) {
        dprintf(2, "xor\n");
        xor_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return (1);
    }
    if (handling_pc_three(arena, core, i) == 1)
        return (1);
    return (0);
}

void handling_pc(char *arena, core_t *core, int i)
{
    if (core->champs[i].to_wait.nb_toexe == 0)
        return;
    if (core->champs[i].to_wait.nb_toexe == 0x01) {
        dprintf(2, "live\n");
        live_function(core, arena, core->champs[i].pc, i);
        return;
    }
    if (core->champs[i].to_wait.nb_toexe == 0x02) {
        dprintf(2, "ld\n");
        ld_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return;
    }
    if (core->champs[i].to_wait.nb_toexe == 0x03) {
        dprintf(2, "st\n");
        st_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return;
    }
    if (core->champs[i].to_wait.nb_toexe == 0x04) {
        dprintf(2, "add\n");
        dprintf(2, "IDX OF CODING BYTE (ADD) : %d\n", core->champs[i].pc + 1);
        add_function(&core->champs[i], arena, arena[core->champs[i].pc + 1]);
        return;
    }
    if (core->champs[i].to_wait.nb_toexe == 0x0c) {
        dprintf(2, "fork\n");
        fork_function(core, i, arena, core->champs[i].pc);
        return;
    }
    if (handling_pc_two(arena, core, i) == 1)
        return;
    return;
}

void waiter_three(char *arena, core_t *core, int i)
{
    if (arena[core->champs[i].pc] == 0x09) {
        core->champs[i].to_wait.ctw = 20;
        core->champs[i].to_wait.nb_toexe = 0x09;
    }
    if (arena[core->champs[i].pc] == 0x0a) {
        dprintf(2, "ldi waiter\n");
        core->champs[i].to_wait.ctw = 25;
        core->champs[i].to_wait.nb_toexe = 0x0a;
    }
    if (arena[core->champs[i].pc] == 0x0c) {
        core->champs[i].to_wait.ctw = 800;
        core->champs[i].to_wait.nb_toexe = 0x0c;
    }
    if (arena[core->champs[i].pc] == 0x0d) {
        core->champs[i].to_wait.ctw = 10;
        core->champs[i].to_wait.nb_toexe = 0x0d;
    }
}

void waiter_second(char *arena, core_t *core, int i)
{
    if (arena[core->champs[i].pc] == 0x05) {
        core->champs[i].to_wait.ctw = 10;
        core->champs[i].to_wait.nb_toexe = 0x05;
    }
    if (arena[core->champs[i].pc] == 0x06) {
        core->champs[i].to_wait.ctw = 6;
        core->champs[i].to_wait.nb_toexe = 0x06;
    }
    if (arena[core->champs[i].pc] == 0x07) {
        core->champs[i].to_wait.ctw = 6;
        core->champs[i].to_wait.nb_toexe = 0x07;
    }
    if (arena[core->champs[i].pc] == 0x08) {
        core->champs[i].to_wait.ctw = 6;
        core->champs[i].to_wait.nb_toexe = 0x08;
    }
    if (core->champs[i].to_wait.ctw == 0)
        waiter_three(arena, core, i);
}

void waiter(char *arena, core_t *core, int i)
{
    if (arena[core->champs[i].pc] == 0x01) {
        core->champs[i].to_wait.ctw = 10;
        core->champs[i].to_wait.nb_toexe = 0x01;
    }
    if (arena[core->champs[i].pc] == 0x02) {
        core->champs[i].to_wait.ctw = 5;
        core->champs[i].to_wait.nb_toexe = 0x02;
    }
    if (arena[core->champs[i].pc] == 0x03) {
        core->champs[i].to_wait.ctw = 5;
        core->champs[i].to_wait.nb_toexe = 0x03;
    }
    if (arena[core->champs[i].pc] == 0x04) {
        core->champs[i].to_wait.ctw = 10;
        core->champs[i].to_wait.nb_toexe = 0x04;
    }
    if (core->champs[i].to_wait.ctw == 0)
        waiter_second(arena, core, i);
}

void handling_pcs(core_t *core)
{
    int nb = core->nb_champs;

    for (int i = 0; i < nb; i += 1) {
        if (core->champs[i].to_wait.ctw == 0) {
            dprintf(2, "done\n");
            handling_pc(core->arena, core, i);
            waiter(core->arena, core, i);
        }
        else if (core->champs[i].status == 1) {
            core->champs[i].to_wait.ctw -= 1;
            dprintf(2, "core->champs[i].to_wait.ctw = %d && core->champs[i].to_wait.nb_toexe = %d\n", core->champs[i].to_wait.ctw, core->champs[i].to_wait.nb_toexe);
        }
    }
}
