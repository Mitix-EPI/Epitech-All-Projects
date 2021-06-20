/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** find
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int len_this = strlen(this->str);
    size_t len_str = strlen(str->str);
    int i = pos;

    for (; i < len_this; i++) {
        if (strncmp(this->str + i, str->str, len_str) == 0) {
            return i;
        }
    }
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int len_this = strlen(this->str);
    size_t len_str = strlen(str);
    int i = pos;

    for (; i < len_this; i++) {
        if (strncmp(this->str + i, str, len_str) == 0) {
            return i;
        }
    }
    return -1;
}
