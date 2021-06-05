/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <string>
#include <map>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0; // Simulate a tick
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0; // Set link
            virtual void dump() const = 0; // Write
    };
} // namespace nts

#endif /* !ICOMPONENT_HPP_ */
