/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename T>
T min(T a, T b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return a;
    else
        return b;
}

template<typename T>
T templateMin(T *a, int b)
{
    T res = a[0];
    for (int i = 1; i < b; i++) {
        res = ::min<T>(a[i], res);
    }
    return res;
}

int nonTemplateMin(int *a, int b)
{
    int res = a[0];
    for (int i = 1; i < b; i++) {
        res = min(a[i], res);
    }
    return res;
}

#endif /* !EX02_HPP_ */
