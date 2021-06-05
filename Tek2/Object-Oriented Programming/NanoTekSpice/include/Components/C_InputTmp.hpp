/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-tekspice-cyril.grosjean
** File description:
** C_InputTmp
*/

#ifndef C_INPUTTMP_HPP_
#define C_INPUTTMP_HPP_

#include "Component.hpp"

class C_InputTmp : public Component {
    public:
        C_InputTmp();
        ~C_InputTmp();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;
        void switchValue(void);

    protected:
    private:
};

#endif /* !C_INPUTTMP_HPP_ */
