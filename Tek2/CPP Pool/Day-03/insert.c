/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** insert
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    int len = strlen(this->str);

    if (!str)
        return;
    if (!this->str)
        return assign_c(this, str);
    if (pos > strlen(this->str))
        return append_c(this, str);
    char *tmp1 = (char *)calloc(pos + 1, sizeof(char));
    char *tmp2 = (char *)calloc(len - pos + 1, sizeof(char));
    strncpy(tmp1, this->str, pos);
    strncpy(tmp2, this->str + pos, len - pos);
    assign_c(this, tmp1);
    append_c(this, str);
    append_c(this, tmp2);
    free(tmp1);
    free(tmp2);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int len = strlen(this->str);

    if (!str || !str->str)
        return;
    if (!this->str)
        return assign_s(this, str);
    if (pos > strlen(this->str))
        return append_s(this, str);
    char *tmp1 = (char *)calloc(pos + 1, sizeof(char));
    char *tmp2 = (char *)calloc(len - pos + 1, sizeof(char));
    strncpy(tmp1, this->str, pos);
    strncpy(tmp2, this->str + pos, len - pos);
    assign_c(this, tmp1);
    append_c(this, str->str);
    append_c(this, tmp2);
    free(tmp1);
    free(tmp2);
}
