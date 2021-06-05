/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_True
*/

#ifndef C_TRUE_HPP_
#define C_TRUE_HPP_

#include "Component.hpp"

class C_True : public Component {
    public:
        C_True();
        ~C_True();

        void simulate(std::size_t tick) { (void) tick; }
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

    protected:
    private:
};

#endif /* !C_TRUE_HPP_ */
