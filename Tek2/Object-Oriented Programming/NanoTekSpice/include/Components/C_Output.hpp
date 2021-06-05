/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_Input
*/

#ifndef C_OUTPUT_HPP_
#define C_OUTPUT_HPP_

#include "Component.hpp"

class C_Output : public Component {
    public:
        C_Output();
        ~C_Output();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

    protected:
    private:
};

#endif /* !C_OUTPUT_HPP_ */
