/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_into_arena
*/

#include "corewar.h"

void write_into_arena(char *arena, int pos, int value)
{
    int oct_a = value & 0xFF;
    int oct_b = (value >> 8) && 0xFF;
    int oct_c = (value >> 16) && 0xFF;
    int oct_d = (value >> 24) && 0xFF;
    arena[pos % MEM_SIZE] = oct_d;
    arena[(pos + 1) % MEM_SIZE] = oct_c;
    arena[(pos + 2) % MEM_SIZE] = oct_b;
    arena[(pos + 3) % MEM_SIZE] = oct_a;
}
