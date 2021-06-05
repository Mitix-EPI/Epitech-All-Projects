/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Misc
*/

#ifndef MISC_HPP_
#define MISC_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace misc {
    bool isNumber(std::string str);
    std::vector<std::string> split(std::string line, char sep);
};

#endif /* !MISC_HPP_ */
