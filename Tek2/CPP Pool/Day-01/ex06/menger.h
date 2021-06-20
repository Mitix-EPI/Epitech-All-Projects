/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** menger
*/

#ifndef MENGER_H_
#define MENGER_H_

#include "drawing.h"

int menger(int sizeSquare, point_t point, int nbLevel, unsigned int **img);
void loop(int sizeSquare, point_t point, int nbLevel, unsigned int **img);

#endif /* !MENGER_H_ */
