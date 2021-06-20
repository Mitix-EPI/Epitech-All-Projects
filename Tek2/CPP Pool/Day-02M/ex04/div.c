/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02M-alexandre.juan
** File description:
** div
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return 0;
    return a / b;
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return 0;
    return ((double)a / (double)b);
}

void exec_div(division_t *operation)
{
    if (operation->div_type == INTEGER) {
        integer_op_t* integ = operation->div_op;
        integ->res = integer_div(integ->a, integ->b);
    } else if (operation->div_type == DECIMALE) {
        decimale_op_t* deci = operation->div_op;
        deci->res = decimale_div(deci->a, deci->b);
    }
}
