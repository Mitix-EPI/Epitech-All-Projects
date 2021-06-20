/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** join
*/

#include "string.h"

void join_c(string_t *this, char delim, const char * const *tab)
{
    char delimitation[1];

    if (!this || !tab)
        return;
    delimitation[0] = delim;
    assign_c(this, tab[0]);
    append_c(this, delimitation);
    for (int i = 1; tab[i] != NULL; i++) {
        append_c(this, tab[i]);
        append_c(this, delimitation);
    }
    this->str[size(this) - 1] = '\0';
}

void join_s(string_t *this, char delim, const string_t * const *tab)
{
    char delimitation[1];

    if (!this || !tab)
        return;
    delimitation[0] = delim;
    assign_s(this, tab[0]);
    append_c(this, delimitation);
    for (int i = 1; tab[i] != NULL; i++) {
        append_s(this, tab[i]);
        append_c(this, delimitation);
    }
    this->str[size(this) - 1] = '\0';
}
