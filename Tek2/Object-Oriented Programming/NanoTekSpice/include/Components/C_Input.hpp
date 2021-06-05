/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_Input
*/

#ifndef C_INPUT_HPP_
#define C_INPUT_HPP_

#include "Component.hpp"

class C_Input : public Component {
    public:
        C_Input();
        ~C_Input();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

    protected:
    private:
};

#endif /* !C_INPUT_HPP_ */
