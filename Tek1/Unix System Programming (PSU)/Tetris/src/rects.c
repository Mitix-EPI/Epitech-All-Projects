/*
** EPITECH PROJECT, 2020
** starting_tetris
** File description:
** rects
*/

#include <stdio.h>
#include <unistd.h>

void line_loop(char a, char b, char c, int x)
{
    write(1, &a, 1);
    for (int j = 0; j < x - 2; j++)
        write(1, &b, 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}

void display_rect(int *size, char *characters)
{
    int x = size[0];
    int y = size[1];
    for (int i = 0; i < y; i++) {
        if (i == 0) {
            line_loop(characters[0], characters[4], characters[1], x);
        } else if (i == y - 1) {
            line_loop(characters[2], characters[4], characters[3], x);
        } else
            line_loop(characters[5], ' ', characters[5], x);
    }
}