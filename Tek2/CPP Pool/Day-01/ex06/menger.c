/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** menger
*/

#include "menger.h"
#include "drawing.h"
#include "bitmap.h"

void loop(int sizeSquare, point_t point, int nbLevel, unsigned int **img)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 || j != 1) {
                int nextX = (sizeSquare * i) + point.x;
                int nextY = (sizeSquare * j) + point.y;
                point_t tmp;
                tmp.x = nextX;
                tmp.y = nextY;
                menger(sizeSquare, tmp, nbLevel - 1, img);
            }
        }
    }
}

int menger(int sizeSquare, point_t point, int nbLevel, unsigned int **img)
{
    sizeSquare /= 3;
    int col = 0xFF / nbLevel;
    int color = ((col & 0xff) << 16) + ((col & 0xff) << 8) + (col & 0xff);

    point_t tmp = {sizeSquare + point.x, sizeSquare + point.y};
    draw_square(img, &tmp, (size_t)sizeSquare, color);
    if (nbLevel <= 0) {
        return 0;
    }
    if (nbLevel > 1)
        loop(sizeSquare, point, nbLevel, img);
    return 0;
}
