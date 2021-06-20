/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** drawing
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin,\
size_t size, uint32_t color)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            img[i + origin->y][j + origin->x] = color;
        }
    }
}
