/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** menger
*/

#include "menger.h"

void loop(int sizeSquare, int x, int y, int nbLevel)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 || j != 1) {
                int nextX = (sizeSquare * i) + x;
                int nextY = (sizeSquare * j) + y;
                menger(sizeSquare, nextX, nextY, nbLevel - 1);
            }
        }
    }
}

int menger(int sizeSquare, int x, int y, int nbLevel)
{
    sizeSquare /= 3;
    printf("%03d %03d %03d\n", sizeSquare, sizeSquare + x, sizeSquare + y);
    if (nbLevel <= 0) {
        return 0;
    }
    if (nbLevel > 1)
        loop(sizeSquare, x, y, nbLevel);
    return 0;
}
