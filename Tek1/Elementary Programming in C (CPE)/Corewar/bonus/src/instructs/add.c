/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add
*/

#include "corewar.h"

void add_regs(champions_t *champ, char *arena, int arg_1, int arg_2)
{
    int arg_3 = arg_2 + 1;

    arg_1 = give_int(arena, arg_1, 1);
    arg_2 = give_int(arena, arg_2, 1);
    arg_3 = give_int(arena, arg_3, 1);
    champ->reg[arg_3 - 1] = champ->reg[arg_1 - 1] + champ->reg[arg_2 - 1];
    champ->pc += 4;
    champ->wait += 5;
    // champ->carry = 0;
}

void add_function(champions_t *champ, char *arena, int coding_byte)
{
    if (coding_byte == 84) {
        add_regs(champ, arena, champ->pc + 2, champ->pc + 3);
        return;
    }
    // champ->carry = 1;
    my_putstr(2, "error\n");
}
