/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** empty
*/

#include "string.h"

int empty(const string_t *this)
{
    if (!this->str || this->str[0] == '\0')
        return 1;
    return 0;
}
