/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template<typename T>
T add(T a, T b)
{
    return a + b;
}

template<typename T>
T min(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}

template<typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template<typename T>
void swap(T &a, T &b)
{
    T tmp = b;
    b = a;
    a = tmp;
}

#endif /* !EX00_HPP_ */
