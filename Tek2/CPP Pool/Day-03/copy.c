/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** copy
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    for (; (i == 0 || this->str[i - 1] != '\0') && i < n; i++) {
        s[i] = this->str[i + pos];
    }
    return i;
}
