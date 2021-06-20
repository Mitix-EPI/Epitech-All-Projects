/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include <string>
#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(std::string serial);
        Droid(const Droid &other);
        ~Droid();

        // operators
        Droid &operator=(const Droid &ptr);
        bool operator==(const Droid &ptr) const;
        bool operator!=(const Droid &ptr) const;
        Droid &operator<<(size_t &energ);
        bool operator()(std::string *task, size_t exp);

        // getters
        std::string getId(void) const;
        size_t getEnergy(void) const;
        size_t getAttack(void) const;
        size_t getToughness(void) const;
        std::string *getStatus(void) const;
        DroidMemory *getBattleData(void) const { return BattleData; }

        // setters
        void setId(std::string newId);
        void setEnergy(size_t newEnergy);
        void setStatus(std::string *newStatus);
        void setBattleData(DroidMemory *droidMemory);


    protected:
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        DroidMemory *BattleData;

};

std::ostream &operator<<(std::ostream &s, const Droid &d);

#endif /* !DROID_HPP_ */
