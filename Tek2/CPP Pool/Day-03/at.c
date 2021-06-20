/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** at
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (strlen(this->str) <= pos)
        return -1;
    return this->str[pos];
}
