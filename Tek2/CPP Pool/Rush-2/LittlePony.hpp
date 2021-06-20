/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include "main_santa.hpp"
#include "Toy.hpp"

class LittlePony : public Toy {
    public:
        LittlePony(std::string name);
        ~LittlePony();
        void isTaken(void) const;
    protected:
    private:
};

std::ostream &operator<<(std::ostream &s, const LittlePony &teddy);

#endif /* !LITTLEPONY_HPP_ */
