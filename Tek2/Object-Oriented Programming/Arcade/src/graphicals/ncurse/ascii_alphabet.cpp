/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** ascii_alphabet
*/

#include "ascii_alphabet.hpp"

std::vector<std::string> getAsciiLetter(char letter)
{
    switch (letter)
    {
        case 'A':
            return ascii_A;
        case 'B':
            return ascii_B;
        case 'C':
            return ascii_C;
        case 'D':
            return ascii_D;
        case 'E':
            return ascii_E;
        case 'F':
            return ascii_F;
        case 'G':
            return ascii_G;
        case 'H':
            return ascii_H;
        case 'I':
            return ascii_I;
        case 'J':
            return ascii_J;
        case 'K':
            return ascii_K;
        case 'L':
            return ascii_L;
        case 'M':
            return ascii_M;
        case 'N':
            return ascii_N;
        case 'O':
            return ascii_O;
        case 'P':
            return ascii_P;
        case 'Q':
            return ascii_Q;
        case 'R':
            return ascii_R;
        case 'S':
            return ascii_S;
        case 'T':
            return ascii_T;
        case 'U':
            return ascii_U;
        case 'V':
            return ascii_V;
        case 'W':
            return ascii_W;
        case 'X':
            return ascii_X;
        case 'Y':
            return ascii_Y;
        case 'Z':
            return ascii_Z;
    };
    return ascii_A;
}
