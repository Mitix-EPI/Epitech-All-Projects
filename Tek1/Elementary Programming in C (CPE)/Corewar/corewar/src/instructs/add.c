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
    int add = 0;

    arg_1 = give_int(arena, arg_1, T_REG);
    arg_2 = give_int(arena, arg_2, T_REG);
    arg_3 = give_int(arena, arg_3, T_REG);
    add = champ->reg[arg_1 - 1] + champ->reg[arg_2 - 1];
    champ->reg[arg_3 - 1] = champ->reg[arg_1 - 1] + champ->reg[arg_2 - 1];
    champ->pc += 4;
    champ->carry = 1;
}

void add_function(champions_t *champ, char *arena, int coding_byte)
{
    champ->to_wait.nb_toexe = 0;
    champ->to_wait.ctw = 0;
    dprintf(2, "coding_byte du ADD : %d\n", coding_byte);
    if (coding_byte == 84) {
        add_regs(champ, arena, champ->pc + 2, champ->pc + 3);
        return;
    }
    champ->carry = 0;
    // my_putstr(2, "add error\n");
}
