/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** and
*/

#include "corewar.h"

void and_calcs(champions_t *champ, char *arena, int *args)
{
    int idx = 2;
    int arg1 = give_int(arena, champ->pc + idx, args[0]);
    int arg2 = 0;
    int arg3 = 0;
    int res = 0;

    idx += args[0];
    arg2 = give_int(arena, champ->pc + idx, args[1]);
    idx += args[1];
    arg3 = give_int(arena, champ->pc + idx, args[2]);
    res = arg1 & arg2;
    champ->reg[arg3 - 1] = arg1 & arg2;
    champ->pc += idx;
    champ->carry = 1;
}

void and_first_register(champions_t *champ, char *arena, int coding_byte)
{
    int args[3] = {0};

    if (coding_byte == 100) {
        args[0] = 1;
        args[1] = 4;
        args[2] = 1;
    }
    if (coding_byte == 84) {
        args[0] = 1;
        args[1] = 1;
        args[2] = 1;
    }
    if (coding_byte == 116) {
        args[0] = 1;
        args[1] = 2;
        args[2] = 1;
    }
    and_calcs(champ, arena, args);
}
void and_first_direct(champions_t *champ, char *arena, int coding_byte)
{
    int args[3] = {0};

    if (coding_byte == -92) {
        args[0] = 4;
        args[1] = 4;
        args[2] = 1;
    }
    if (coding_byte == -76) {
        args[0] = 4;
        args[1] = 2;
        args[2] = 1;
    }
    if (coding_byte == -108) {
        args[0] = 4;
        args[1] = 1;
        args[2] = 1;
    }
    and_calcs(champ, arena, args);
}

void and_first_indirect(champions_t *champ, char *arena, int coding_byte)
{
    int args[3] = {1};

    if (coding_byte == -12) {
        args[0] = 2;
        args[1] = 2;
        args[2] = 1;
    }
    if (coding_byte == -28) {
        args[0] = 2;
        args[1] = 4;
        args[2] = 1;
    }
    if (coding_byte == -44) {
        args[0] = 2;
        args[1] = 1;
        args[2] = 1;
    }
    and_calcs(champ, arena, args);
}

void and_function(champions_t *champ, char *arena, int coding_byte)
{
    dprintf(2, "coding byte and : %d\n", coding_byte);
    champ->to_wait.nb_toexe = 0;
    champ->to_wait.ctw = 0;
    if (coding_byte == 100 || coding_byte == 84 || coding_byte == 116) {
        and_first_register(champ, arena, coding_byte);
        return;
    }
    if (coding_byte == -92 || coding_byte == -76 || coding_byte == -108) {
        and_first_direct(champ, arena, coding_byte);
        return;
    }
    if (coding_byte == -12 || coding_byte == -28 || coding_byte == -44) {
        and_first_indirect(champ, arena, coding_byte);
        return;
    }
    my_putstr(2, "Coding Byte not recognized\n");
    champ->carry = 0;
    return;
}
