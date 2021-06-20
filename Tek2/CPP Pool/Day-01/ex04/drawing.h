/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** drawing
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include "bitmap.h"

typedef struct point_t
{
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square (uint32_t ** img ,const point_t * origin,\
size_t size, uint32_t color);

#endif /* !DRAWING_H_ */
