/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** lld
*/

#include "corewar.h"

void store_value_in_reg_lld(champions_t *champ, char *arena, int *args, int bts)
{
    int arg_1 = args[0];
    int arg_2 = args[1];

    champ->reg[arg_2 - 1] = arg_2;
    champ->pc += bts;
}

void lld_function(champions_t *champ, char *arena, int coding_byte)
{
    coding_byte &= 0xff;
    champ->to_wait.nb_toexe = 0;
    champ->to_wait.ctw = 0;
    if (coding_byte == 0xd0) {
        store_value_in_reg_lld(champ, arena, (int [2]) \
        { give_int(arena, champ->pc + 2, T_DIR), \
        give_int(arena, champ->pc + 4, T_REG) }, 5);
        return;
    }
    if (coding_byte == 0x90) {
        store_value_in_reg_lld(champ, arena, (int [2]) \
        { give_int(arena, champ->pc + 2, T_IND), \
        give_int(arena, champ->pc + 6, T_REG) }, 7);
        return;
    }
    // my_putstr(2, "lld error\n");
}