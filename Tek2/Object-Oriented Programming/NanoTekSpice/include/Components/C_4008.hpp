/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4008
*/

#ifndef C_4008_HPP_
#define C_4008_HPP_

#include <unordered_map>
#include <functional>
#include <utility> // std::pair

#include "Component.hpp"
#include "IComponent.hpp"

class C_4008 : public Component {
    public:
        C_4008();
        ~C_4008();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

        nts::Tristate computeInput(std::size_t pin) const;
        nts::Tristate computeOutput(std::size_t pin);
        nts::Tristate computeVSS(std::size_t pin) const;
        nts::Tristate computeVDD(std::size_t pin) const;
        nts::Tristate convertCalc(std::size_t pin1, std::size_t pin2) const;
        bool isUndefined(std::size_t pin) const;

        nts::Tristate returnBit(std::size_t pin1, std::size_t pin2, std::size_t pin3, bool carryIn);

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;

        nts::Tristate _CarryIn;
        nts::Tristate _A;
        nts::Tristate _B;
};

#endif /* !C_4008_HPP_ */
