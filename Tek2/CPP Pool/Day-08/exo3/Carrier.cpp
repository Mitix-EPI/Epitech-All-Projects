/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::~Carrier()
{
    for (int i = 0; i < 5; i++) {
        if (Droids[i] != nullptr)
            delete Droids[i];
    }
}

Carrier &Carrier::operator<<(const Droid *ptr)
{
    for (int i = 0; i < 5; i++) {
        if (Droids[i] == nullptr) {
            Droids[i] = new Droid(*ptr);
            updateSpeed();
            return *this;
        }
    }
    return *this;
}

Carrier &Carrier::operator>>(Droid *ptr)
{
    for (int i = 0; i < 5; i++) {
        if (*Droids[i] == (*ptr)) {
            ptr = new Droid(*(Droids[i]));
            Droids[i] = nullptr;
            updateSpeed();
            return *this;
        }
    }
    return *this;
}

Droid *Carrier::operator[](size_t index)
{
    return Droids[index];
}

size_t Carrier::getSize(void) const
{
    size_t count = 0;

    for (size_t i = 0; i < 5; i++) {
        if (Droids[i] != nullptr) {
            count++;
        }
    }
    return count;
}

void Carrier::updateSpeed(void)
{
    size_t count = getSize();

    if (count == 1) {
        setSpeed(100);
    }
    if (count > 0) {
        setSpeed(getSpeed() - 10);
    }
}

bool Carrier::operator()(int x, int y)
{
    int energyCost = (abs(x) + abs(y)) * (10 + ((int)getSize()));
    if (getSize() == 0 || energyCost > (int)getEnergy()) {
        return false;
    }
    return true;
}

Carrier &Carrier::operator<<(size_t &ener)
{
    std::string test;
    size_t diff = 600 - this->Energy;

    if (ener > diff) {
        ener -= diff;
        this->Energy += diff;
    } else {
        this->Energy += ener;
        ener = 0;
    }
    return *this;
}

void Carrier::setId(std::string newId)
{
    Id = newId;
}

void Carrier::setEnergy(size_t newEnergy)
{
    Energy = newEnergy;
}

void Carrier::setSpeed(size_t newSpeed)
{
    Speed = newSpeed;
}

std::ostream &operator<<(std::ostream &s, const Carrier &c)
{
    s << "Carrier '" << c.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++) {
        s << "[" << i << "] : ";
        if (c.getDroids(i) == nullptr) {
            s << "Free";
        } else {
            s << "Droid '" << c.getDroids(i)->getId() << "', " << c.getDroids(i)->getStatus() << ", " << c.getDroids(i)->getEnergy();
        }
        s << std::endl;
    }
    s << "Speed : " << c.getSpeed() << ", Energy " << c.getEnergy() << std::endl;
    return s;
}
