/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class SickKoala {
    public:
        SickKoala(std::string);
        ~SickKoala();
        void poke(void);
        bool takeDrug(std::string);
        void overDrive(std::string);
        std::string getName(void);

    protected:
    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */
