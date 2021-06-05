/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** C_4013
*/

#ifndef C_4013_HPP_
#define C_4013_HPP_

#include <unordered_map>
#include <functional>
#include <utility> // std::pair

#include "Component.hpp"
#include "IComponent.hpp"
#include "Exceptions.hpp"

class C_4013 : public Component {
    public:
        C_4013();
        ~C_4013();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

        void calcOutput(std::size_t pin);
        nts::Tristate computeInput(std::size_t pin) const;
        nts::Tristate computeOutput(std::size_t pin);
        nts::Tristate computeVSS(std::size_t pin) const;
        nts::Tristate computeVDD(std::size_t pin) const;
        nts::Tristate convertCalc(std::string name, std::size_t inputSet, std::size_t inputData, std::size_t inputReset, std::size_t clock, std::size_t qVal) const;

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;
        std::unordered_map<std::size_t, nts::Tristate> _outputs;
        nts::Tristate _Q1;
        nts::Tristate _Qb1;
        nts::Tristate _Q2;
        nts::Tristate _Qb2;
};

#endif /* !C_4013_HPP_ */
