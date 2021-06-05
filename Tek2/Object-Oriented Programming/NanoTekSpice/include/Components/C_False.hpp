/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_False
*/

#ifndef C_FALSE_HPP_
#define C_FALSE_HPP_

#include "Component.hpp"

class C_False : public Component {
    public:
        C_False();
        ~C_False();

        void simulate(std::size_t tick) { (void) tick; }
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

    protected:
    private:
};

#endif /* !C_FALSE_HPP_ */
