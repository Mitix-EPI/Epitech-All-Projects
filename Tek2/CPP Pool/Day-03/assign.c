/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    this->str = (char *)calloc(strlen(str->str) + 1, sizeof(char));
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char * s)
{
    if (this->str)
        free(this->str);
    this->str = (char *)calloc(strlen(s) + 1, sizeof(char));
    strcpy(this->str, s);
}
