/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void foreach(T *a, void func(const T &elem), int it)
{
    for (int i = 0; i < it; i++)
        func(a[i]);
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif /* !EX03_HPP_ */
