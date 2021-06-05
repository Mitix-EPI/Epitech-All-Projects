/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** C_4094
*/

#ifndef C_4094_HPP_
#define C_4094_HPP_

#include "Component.hpp"

class C_4094 : public Component {
    public:
        C_4094();
        ~C_4094();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

        nts::Tristate computeInput(std::size_t pin) const;
        nts::Tristate computeOutput(std::size_t pin);
        nts::Tristate computeVSS(std::size_t pin) const;
        nts::Tristate computeVDD(std::size_t pin) const;
        nts::Tristate convertCalc(std::size_t pin1, std::size_t pin2) const;

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;
        nts::Tristate _metamorph;

        std::unordered_map<std::size_t, nts::Tristate> _outputs;
};

#endif /* !C_4094_HPP_ */
