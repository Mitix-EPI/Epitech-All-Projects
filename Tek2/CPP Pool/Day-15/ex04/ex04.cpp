/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex04
*/

#include "ex04.hpp"

template <>
bool Tester<int>::equal(const int a, const int b)
{
    if (a == b)
        return true;
    else
        return false;
}

template <>
bool Tester<float>::equal(const float a, const float b)
{
    if (a == b)
        return true;
    else
        return false;
}

template <>
bool Tester<double>::equal(const double a, const double b)
{
    if (a == b)
        return true;
    else
        return false;
}

template <>
bool Tester<std::string>::equal(const std::string a, const std::string b)
{
    if (a == b)
        return true;
    else
        return false;
}
