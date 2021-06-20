/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>
#include <iostream>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPacks = 15);
        ~Skat();

        int &stimPaks();
        int stimPaks(int stimPaks);
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();

    protected:
    private:
        std::string _name;
        int _stimPaks;
};

#endif /* !SKAT_HPP_ */
