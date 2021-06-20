/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** size
*/

#include "string.h"

int size(const string_t *this)
{
    if (!this->str)
        return -1;
    return strlen(this->str);
}
