/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include "string.h"

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return 0;
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

template<>
int compare<const char *>(const char * const &a, const char * const &b)
{
    if (strcmp(a, b) == 0)
        return 0;
    if (strcmp(a, b) < 0)
        return -1;
    if (strcmp(a, b) > 0)
        return 1;
    return 0;
}

#endif /* !EX01_HPP_ */
