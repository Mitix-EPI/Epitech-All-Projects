/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex04
*/

#ifndef EX04_HPP_
#define EX04_HPP_

#include <string>

template<typename T>
bool equal(const T a, const T b)
{
    if (a == b)
        return true;
    else
        return false;
}

template<typename T>
class Tester {
    public:
        bool equal(const T a, const T b);
};

#endif /* !EX04_HPP_ */
