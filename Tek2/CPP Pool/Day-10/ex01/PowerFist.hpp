/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include <string>
#include <iostream>
#include "AWeapon.hpp"

class PowerFist : virtual public AWeapon {
    public:
        PowerFist() : AWeapon("Power Fist", 8, 50)
        {
        }
        ~PowerFist();
        void attack() const override;

    protected:
    private:

};

#endif /* !POWERFIST_HPP_ */
