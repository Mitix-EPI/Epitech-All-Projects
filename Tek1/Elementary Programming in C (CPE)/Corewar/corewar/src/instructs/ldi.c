/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** ldi
*/

#include "corewar.h"

void ldi_function_part_two(champions_t *champ, char *arena)
{
    int arg1 = give_int(arena, champ->pc + 2, T_DIR);
    int arg2 = give_int(arena, champ->pc + 2 + 2, T_DIR);
    int arg3 = give_int(arena, champ->pc + 2 + 2 + 1, T_REG);
    int read = give_int(arena, (champ->pc + arg1) % IDX_MOD, IND_SIZE);
    int value = 0;

    read += arg2;
    value = give_int(arena, (champ->pc + read) % IDX_MOD, REG_SIZE);
    champ->reg[arg3 - 1] = value;
    champ->pc += 7;
}

void ldi_function(champions_t *champ, char *arena, int coding_byte)
{
    champ->to_wait.nb_toexe = 0;
    champ->to_wait.ctw = 0;
    dprintf(2, "coding_byte : %d le pc se trouve là : %d\n", coding_byte, champ->pc);
    if (coding_byte == 0 && champ->carry == 1) { //changer coding_byte
        dprintf(2, "LDI ACTIVATED\n");
        ldi_function_part_two(champ, arena);
    }
    if (coding_byte == 0 && champ->carry == 1) { //changer coding_byte
        ldi_function_part_two(champ, arena);
    }
    champ->carry = 1;
    my_putstr(2, "Not good coding byte\n");
}
