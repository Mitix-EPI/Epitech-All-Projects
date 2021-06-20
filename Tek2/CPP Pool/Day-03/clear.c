/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** clear
*/

#include "string.h"

void clear(string_t *this)
{
    free(this->str);
    this->str = (char *)calloc(1, sizeof(char));
    this->str[0] = '\0';
}
