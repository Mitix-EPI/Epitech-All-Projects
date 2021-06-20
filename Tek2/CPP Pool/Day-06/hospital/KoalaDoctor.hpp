/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        std::string name;
        int workTime;
        void diagnose(SickKoala *);
        void timeCheck(void);
        std::string getName(void);

    protected:
    private:
};

#endif /* !KOALADOCTOR_HPP_ */
