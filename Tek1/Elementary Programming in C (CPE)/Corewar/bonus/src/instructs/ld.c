/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** ld
*/

#include "corewar.h"

void store_value_in_reg(champions_t *champ, char *arena, int arg_1, int arg_2)
{
    int value = 0;

    arg_1 = give_int(arena, champ->pc + 2, 2);
    arg_2 = arena[arg_2] & 0xff;
    dprintf(2, "first arg : %d in reg [%d]\n", arg_1, arg_2 - 1);
    value = give_int(arena, champ->pc + arg_1 % IDX_MOD, 1);
    champ->reg[arg_2 - 1] = arg_2;
    champ->pc += 4;
    champ->pc += 5;
}

void ld_function(champions_t *champ, char *arena, int coding_byte)
{
    coding_byte &= 0xff;
    if (coding_byte == 0xd0) {
        store_value_in_reg(champ, arena, champ->pc + 2, champ->pc + 4);
        return;
    }
    my_putstr(2, "error\n");
}