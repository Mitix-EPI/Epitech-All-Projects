/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02M-alexandre.juan
** File description:
** tab_to_2dtab
*/

#include <stdlib.h>
#include <string.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int tabIncr = 0;
    *res = malloc(sizeof(int *) * (length));
    for (int i = 0; i < length; i++) {
        (*res)[i] = malloc(sizeof(int) * sizeof(width));
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++, tabIncr++) {
            (*res)[i][j] = tab[tabIncr];
        }
    }
}
