/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Squad
*/

#include "Squad.hpp"

Squad::Squad()
{
    _units = *(new std::list<ISpaceMarine *>());
}

Squad::Squad(const Squad &newSquad)
{
    for (ISpaceMarine *tmp : newSquad._units)
        _units.push_back(tmp->clone());
}

Squad::~Squad()
{
    for (ISpaceMarine *tmp : _units)
        delete tmp;
}

int Squad::getCount(void) const
{
    return _units.size();
}

ISpaceMarine *Squad::getUnit(int index)
{
    int i = 0;

    if (index >= this->getCount() || index < 0)
        return nullptr;
    for (ISpaceMarine *tmp : _units) {
        if (i == index)
            return tmp;
        i++;
    }
    return nullptr;
}

int Squad::push(ISpaceMarine *unit)
{
    if (unit == nullptr)
        return this->getCount();
    for (ISpaceMarine *tmp : _units) {
        if (tmp == unit)
            return this->getCount();
    }
    _units.push_back(unit);
    return this->getCount();
}
