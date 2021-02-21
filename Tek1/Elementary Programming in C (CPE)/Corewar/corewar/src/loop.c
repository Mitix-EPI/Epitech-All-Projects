/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** loop
*/

#include "../include/corewar.h"

void handling_i_loop(int *i, core_t *core)
{
    if (core->nb_live == NBR_LIVE) {
        core->ctd -= CYCLE_DELTA;
        core->nb_live = 0;
    }
    if (*i == core->ctd) {
        *i = 0;
        reset_live(core);
    }
    for (int j = 0; j < core->nb_champs; j++) {
        if (core->champs[j].to_wait.ctw == 0)
            core->champs[j].pc += 1;
        if (core->champs[j].pc > MEM_SIZE - 1)
            core->champs[j].pc = 0;
    }
}

void init_screen(void) //à enlever
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
    init_screen(); // à enlever
    for (int i = 0; 1; i++) {
        dprintf(2, "commence le handling\n");
        handling_pcs(core);
        dprintf(2, "fini le handling\n");
        handling_i_loop(&i, core);
        disp_arena(core, i);
    }
    endwin();
}