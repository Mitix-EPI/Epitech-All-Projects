/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_Clock
*/

#ifndef C_CLOCK_HPP_
#define C_CLOCK_HPP_

#include "Component.hpp"

class C_Clock : public Component {
    public:
        C_Clock();
        ~C_Clock();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;
        void switchValue(void);

    protected:
    private:
};

#endif /* !C_CLOCK_HPP_ */
