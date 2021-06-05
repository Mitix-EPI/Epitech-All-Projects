/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"
#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

struct Link {
    nts::IComponent *component = nullptr;
    std::size_t index = nts::Tristate::UNDEFINED;
};

class Component : public nts::IComponent {
    public:
        Component(std::string type);
        ~Component();

        // void simulate(std::size_t tick) = 0;
        // nts::Tristate compute(std::size_t pin) = 0;
        // void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        // void dump() const = 0;


        // SETTERS

        void setName(std::string name) { this->_name = name; }
        void setType(std::string type) { this->_type = type; }
        void setStatus(nts::Tristate status) { this->_status = status; }
        void setPinMax(int pinMax) { this->_pinMax = pinMax; }

        // GETTERS

        std::string getType(void) const { return (this->_type); }
        int getStatus(void) const { return (this->_status); }
        int getPinMax(void) const { return (this->_pinMax); }

    protected:
        std::size_t _pinMax;
        std::string _type;
        std::string _name;
        Link _pin[24];
        nts::Tristate _status = nts::Tristate::UNDEFINED;

        bool _computed;
        std::vector<Component> _linkedComponents;
};

int convertTristateToInt(nts::Tristate state);
nts::Tristate convertIntToTristate(int state);

#endif /* !COMPONENT_HPP_ */
