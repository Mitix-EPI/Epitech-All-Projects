/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** AssaultTerminator
*/

#ifndef ASSAULTTERMINATOR_HPP_
#define ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class AssaultTerminator : public ISpaceMarine {
    public:
        AssaultTerminator();
        AssaultTerminator(const AssaultTerminator &newTerminator);
        virtual ~AssaultTerminator();

        ISpaceMarine *clone(void) const;
        void battleCry(void) const;
        void rangedAttack(void) const;
        void meleeAttack(void) const;

    protected:
    private:
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
