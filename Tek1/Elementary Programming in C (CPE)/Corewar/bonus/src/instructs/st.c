/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** st
*/

#include "corewar.h"

void store_content_reg_in_arena(champions_t *champ, char *arena, int reg, \
int index)
{
    int arg_1 = arena[reg] & 0xff;
    int arg_2 = give_int(arena, champ->pc + 3, 2);

    write_into_arena(arena, champ->pc + arg_2 % IDX_MOD, champ->reg[arg_1 - 1]);
    champ->pc += 4;
    champ->wait += 5;
}

void store_content_reg_in_reg(champions_t *champ, char *arena, int reg1, \
int reg2)
{
    int arg_1 = arena[reg1] & 0xff;
    int arg_2 = arena[reg2] & 0xff;

    champ->reg[arg_2 - 1] = champ->reg[arg_1 - 1];
    champ->pc += 3;
    champ->wait += 5;
}

void st_function(champions_t *champ, char *arena, int coding_byte)
{
    if (coding_byte == 0x70) {
        store_content_reg_in_arena(champ, arena, champ->pc + 2, champ->pc + 3);
        return;
    }
    if (coding_byte == 0x50) {
        store_content_reg_in_reg(champ, arena, champ->pc + 2, champ->pc + 3);
        return;
    }
    my_putstr(2, "error\n");

}
