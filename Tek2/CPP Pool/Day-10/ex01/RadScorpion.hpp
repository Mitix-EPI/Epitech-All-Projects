/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** RadScorpion
*/

#ifndef RADSCORPION_HPP_
#define RADSCORPION_HPP_

#include "AEnemy.hpp"

class RadScorpion : virtual public AEnemy {
    public:
        RadScorpion() : AEnemy(80, "RadScorpion")
        {
            std::cout << "* click click click *" << std::endl;
        }
        ~RadScorpion()
        {
            std::cout << "* SPROTCH *" << std::endl;
        }

    protected:
    private:
};

#endif /* !RADSCORPION_HPP_ */
