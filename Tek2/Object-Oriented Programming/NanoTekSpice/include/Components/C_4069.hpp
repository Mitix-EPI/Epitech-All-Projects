/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4069
*/

#ifndef C_4069_HPP_
#define C_4069_HPP_

#include <unordered_map>
#include <functional>
#include <utility> // std::pair

#include "Component.hpp"
#include "IComponent.hpp"

class C_4069 : public Component {
    public:
        C_4069();
        ~C_4069();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

        nts::Tristate computeInput(std::size_t pin) const;
        nts::Tristate computeOutput(std::size_t pin) const;
        nts::Tristate computeVSS(std::size_t pin) const;
        nts::Tristate computeVDD(std::size_t pin) const;
        nts::Tristate convertCalc(nts::Tristate status) const;

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;
};

#endif /* !C_4069_HPP_ */
