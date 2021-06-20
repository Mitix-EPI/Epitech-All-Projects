/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** SuperMutant
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include "AEnemy.hpp"

class SuperMutant : virtual public AEnemy {
    public:
        SuperMutant() : AEnemy(170, "Super Mutant")
        {
            std::cout << "Gaaah. Me want smash heads!" << std::endl;
        }
        ~SuperMutant()
        {
            std::cout << "Aaargh..." << std::endl;
        }
        void takeDamage(int damage) override;

    protected:
    private:
};

#endif /* !SUPERMUTANT_HPP_ */
