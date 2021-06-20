/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by")), BattleData(new DroidMemory)
{
    std::string test;

    if (Id != test) {
        std::cout << "Droid '" << Id << "' Activated" << std::endl;
    } else {
        std::cout << "Droid '' Activated" << std::endl;
    }
}

Droid::Droid(const Droid &other) : Id(other.getId()), Energy(other.getEnergy()), Attack(25), Toughness(15)
{
    std::string test;
    if (other.Status) {
        Status = new std::string(*other.Status);
        BattleData = new DroidMemory(*(other.getBattleData()));
    } else {
        Status = new std::string("Standing by");
        BattleData = new DroidMemory(*(other.getBattleData()));
    }
    if (Id != test) {
        std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
    } else {
        std::cout << "Droid '' Activated, Memory Dumped" << std::endl;
    }
}

Droid::~Droid()
{
    std::string test;

    if (Status)
        delete Status;
    if (Id != test) {
        std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
    } else {
        std::cout << "Droid '' Destroyed" << std::endl;
    }
}

Droid &Droid::operator=(const Droid &ptr)
{
    Id = ptr.Id;
    Energy = ptr.Energy;
    if (Status)
        delete Status;
    if (BattleData)
        delete BattleData;
    Status = new std::string(*ptr.Status);
    BattleData = new DroidMemory(*(ptr.getBattleData()));
    return *this;
}

bool Droid::operator==(const Droid &ptr) const
{
    if (Status->compare(*ptr.Status) == 0) {
        return true;
    } else {
        return false;
    }
}

bool Droid::operator!=(const Droid &ptr) const
{
    if (Status->compare(*ptr.Status) != 0) {
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &s, const Droid &d)
{
    std::string test;

    if (d.getId() != test) {
        return s << "Droid '" << d.getId() << "', " << *(d.getStatus()) << ", " << d.getEnergy();
    } else {
        return s << "Droid '" << d.getId() << "', " << *(d.getStatus()) << ", " << d.getEnergy();
    }
}

Droid &Droid::operator<<(size_t &ener)
{
    size_t diff = 100 - Energy;

    if (diff > 0) {
        if (diff > ener) {
            Energy += ener;
            ener -= ener;
        } else {
            Energy += diff;
            ener -= diff;
        }
    }
    return *this;
}

std::string Droid::getId(void) const
{
    return Id;
}

size_t Droid::getEnergy(void) const
{
    return Energy;
}

size_t Droid::getAttack(void) const
{
    return Attack;
}

size_t Droid::getToughness(void) const
{
    return Toughness;
}

std::string *Droid::getStatus(void) const
{
    return Status;
}

void Droid::setId(std::string newId)
{
    Id = newId;
}

void Droid::setEnergy(size_t newEnergy)
{
    if (newEnergy > (size_t)100) {
        Energy = (size_t)100;
        return;
    }
    Energy = newEnergy;
}

void Droid::setStatus(std::string *newStatus)
{
    delete Status;
    Status = newStatus;
}

void Droid::setBattleData(DroidMemory *newDroidMemory)
{
    BattleData = newDroidMemory;
}
