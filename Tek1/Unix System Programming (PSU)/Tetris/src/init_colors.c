/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_colors
*/

#include "../include/my.h"

int colornum(int fg, int bg)
{
    int B = 0;
    int bbb = 0;
    int ffff = 0;

    B = 1 << 7;
    bbb = (7 & bg) << 4;
    ffff = 7 & fg;

    return (B | bbb | ffff);
}

int curs_color(int fg)
{
    switch (7 & fg) {
    case 0:
        return (COLOR_BLACK);
    case 1:
        return (COLOR_BLUE);
    case 2:
        return (COLOR_GREEN);
    case 3:
        return (COLOR_CYAN);
    case 4:
        return (COLOR_RED);
    case 5:
        return (COLOR_MAGENTA);
    case 6:
        return (COLOR_YELLOW);
    case 7:
        return (COLOR_WHITE);
    }
    return (0);
}

void init_colorpairs(void)
{
    int fg = 0;
    int bg = 0;
    int colorpair = 0;

    for (bg = 0; bg <= 7; bg++)
        for (fg = 0; fg <= 7; fg++) {
            colorpair = colornum(fg, bg);
            init_pair(colorpair, curs_color(fg), curs_color(bg));
        }
}