/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
** File description:
** append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (!this->str) {
        assign_s(this, ap);
        return;
    }
    char *tmp = (char *)calloc(strlen(this->str) + 1, sizeof(char));
    strcpy(tmp, this->str);
    free(this->str);
    this->str = (char *)calloc(strlen(tmp) + strlen(ap->str) + 1, sizeof(char));
    strcpy(this->str, tmp);
    strcat(this->str, ap->str);
    free(tmp);
}

void append_c(string_t *this, const char *ap)
{
    if (!this->str) {
        assign_c(this, ap);
        return;
    }
    char *tmp = (char *)calloc(strlen(this->str) + 1, sizeof(char));
    strcpy(tmp, this->str);
    free(this->str);
    this->str = (char *)calloc(strlen(tmp) + strlen(ap) + 1, sizeof(char));
    strcpy(this->str, tmp);
    strcat(this->str, ap);
    free(tmp);
}
