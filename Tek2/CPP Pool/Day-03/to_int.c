/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** to_int
*/

#include "string.h"

int to_int(const string_t *this)
{
    return atoi(this->str);
}
