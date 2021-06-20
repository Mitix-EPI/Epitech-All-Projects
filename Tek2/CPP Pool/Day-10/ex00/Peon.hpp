/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(std::string name) : Victim(name)
        {
            _name = name;
            std::cout << "Zog zog." << std::endl;
        }
        ~Peon()
        {
            std::cout << "Bleuark..." << std::endl;
        }

        void getPolymorphed(void) const final;

    protected:
    private:
};

#endif /* !PEON_HPP_ */
