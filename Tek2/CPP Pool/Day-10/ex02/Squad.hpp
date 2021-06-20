/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Squad
*/

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>
#include <list>

class Squad : public ISquad {
    public:
        Squad();
        Squad(const Squad &newSquad);
        virtual ~Squad();

        int getCount(void) const;
        ISpaceMarine *getUnit(int);
        int push(ISpaceMarine *);

    protected:
        std::list<ISpaceMarine *> _units;
    private:
};

#endif /* !SQUAD_HPP_ */
