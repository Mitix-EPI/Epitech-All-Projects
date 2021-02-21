/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** loop
*/

#include "corewar.h"

void handling_i_loop(int *i, core_t *core)
{
    if (*i == core->ctd) {
        *i = 0;
        reser_live(core);
    }
    for (int j = 0; j < core->nb_champs; j++) {
        if (core->champs[j].wait <= 0)
            core->champs[j].pc += 1;
        else
            core->champs[j].wait -= 1;
        if (core->champs[j].pc > MEM_SIZE - 1)
            core->champs[j].pc = 0;
    }
}

void init_screen(void)
{
    initscr();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();
    init_pair(PC_PLAYER1, COLOR_WHITE, COLOR_BLUE);
    init_pair(PC_PLAYER2, COLOR_WHITE, COLOR_RED);
    init_pair(PC_PLAYER3, COLOR_WHITE, COLOR_GREEN);
    init_pair(PC_PLAYER4, COLOR_WHITE, COLOR_YELLOW);

    init_pair(INST_PLAYER1, COLOR_BLUE, COLOR_BLACK);
    init_pair(INST_PLAYER2, COLOR_RED, COLOR_BLACK);
    init_pair(INST_PLAYER3, COLOR_GREEN, COLOR_BLACK);
    init_pair(INST_PLAYER4, COLOR_YELLOW, COLOR_BLACK);

}

void loop(core_t *core)
{
    init_screen();
    for (int i = 0; getch() != '\n'; i++) {
        handling_pcs(core);
        handling_i_loop(&i, core);
        disp_arena(core, i);
    }
    endwin();
}