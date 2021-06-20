/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02M-alexandre.juan
** File description:
** add
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return a + b;
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    return a + b;
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL) {
        operation->add_op.res = normal_add(operation->add_op.a,\
        operation->add_op.b);
    } else if (operation->add_type == ABSOLUTE) {
        operation->add_op.res = absolute_add(operation->add_op.a,\
        operation->add_op.b);
    }
}
