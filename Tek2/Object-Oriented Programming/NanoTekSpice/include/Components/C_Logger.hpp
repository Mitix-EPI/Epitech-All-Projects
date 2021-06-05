/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** C_Logger
*/

#ifndef C_LOGGER_HPP_
#define C_LOGGER_HPP_

#include <unordered_map>
#include <functional>
#include <utility>
#include <cstdint>
#include <fstream>
#include <iostream>

#include "Components.hpp"
#include "IComponent.hpp"

class C_Logger : public Component {
    public:
        C_Logger();
        ~C_Logger();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

        nts::Tristate computeInput(std::size_t pin) const;
        bool computeToBinary(nts::Tristate state) const;
        bool isNotUndefined(void) const;

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;
};

#endif /* !C_LOGGER_HPP_ */
