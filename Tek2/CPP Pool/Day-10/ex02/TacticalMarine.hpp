/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** TacticalMarine
*/

#ifndef TACTICALMARINE_HPP_
#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>
#include <list>

class TacticalMarine : public ISpaceMarine {
    public:
        TacticalMarine();
        TacticalMarine(const TacticalMarine &newMarine);
        virtual ~TacticalMarine();

        ISpaceMarine *clone(void) const;
        void battleCry(void) const;
        void rangedAttack(void) const;
        void meleeAttack(void) const;

    protected:
    private:
};

#endif /* !TACTICALMARINE_HPP_ */
