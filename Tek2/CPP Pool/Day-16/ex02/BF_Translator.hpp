/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** BF_Translator
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_

#include <string>
#include <fstream>
#include <map>
#include <iostream>

class BF_Translator {
    public:
        BF_Translator();
        ~BF_Translator();

        int translate(const std::string &in, const std::string &out);

        std::map<char, std::string> _map;

    protected:
    private:
};

bool isSkipable(char c);
bool isOk(char c);

#endif /* !BF_TRANSLATOR_HPP_ */
