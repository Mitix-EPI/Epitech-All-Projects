/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** prints
*/

#include "../include/my.h"

void my_disp(sokoban_t *s)
{
    clear();
    print_map(s);
}

void print_map(sokoban_t *s)
{
    int count_lines = 0;
    int count_cols = 0;
    char *error = "Screen too small";

    for (int i = 0, y = 1; s->s_mod[i] != NULL; i++, y++) {
        count_lines += 1;
        if (my_strlen(s->s_mod[i]) > count_cols)
            count_cols = my_strlen(s->s_mod[i]);
        mvprintw(y, 1, s->s_mod[i]);
    }
    if (count_cols > COLS || count_lines > LINES) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - (17 / 2), error);
    }
}

int print_usage(char **argv, sokoban_t *s)
{
    s->ch = 0;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t", 37);
        write(1, "map file representing the warehouse map", 40);
        write(1, ", containing '#' ", 18);
        write(1, "for walls,\n\t\t 'p' for the player,", 34);
        write(1, " 'X' for boxes and 'O' ", 24);
        write(1, "for storage locations.", 23);
        return (1);
    }
    return (0);
}