/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** PlasmaRifle
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include <string>
#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : virtual public AWeapon {
    public:
        PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
        {
        }
        ~PlasmaRifle();
        void attack() const override;

    protected:
    private:

};

#endif /* !PLASMARIFLE_HPP_ */
