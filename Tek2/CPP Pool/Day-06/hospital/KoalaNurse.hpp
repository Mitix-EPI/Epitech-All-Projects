/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala *);
        std::string readReport(std::string);
        void timeCheck(void);
        int getID(void);

    protected:
    private:
        int id;
        int workTime;
};

#endif /* !KOALANURSE_HPP_ */
