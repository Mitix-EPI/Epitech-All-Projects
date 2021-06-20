/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <string>
#include <iostream>
#include <algorithm>
#include <list>

template<typename T>
typename T::iterator do_find(T &a, int b)
{
    return std::find(a.begin(), a.end(), b);
}

#endif /* !FIND_HPP_ */
