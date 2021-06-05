/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Misc
*/

#include "Misc.hpp"

bool misc::isNumber(std::string str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) {
            return (false);
        }
    }
    return (true);
}

std::vector<std::string> misc::split(std::string line, char sep)
{
    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> words;

    while (std::getline(ss, word, sep)) {
        words.push_back(word);
    }
    for (std::vector<std::string>::iterator i = words.begin(); i != words.end();) {
        if (i->empty()) {
            i = words.erase(i);
        } else {
            i += 1;
        }
    }
    return (words);
}
