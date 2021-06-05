/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Components.hpp"
#include "ComponentFactory.hpp"
#include "Parser.hpp"
#include <unordered_map>
#include <string>

class Circuit {
    public:
        Circuit(Parser parser);
        ~Circuit();

        void simulate(void);
        void dump(void) const;
        void display(void);
        std::string displayCompute(nts::Tristate);
        void setValue(std::string varName, nts::Tristate status);
        void invertClock(void);
        void reset(void);

    protected:
        void _fill(Parser parser);
        void _setValues(Parser parser);
        void _setLinks(Parser parser);

    private:
        std::vector<C_InputTmp *> _arrayTmp;

        std::map<std::string, std::unique_ptr<nts::IComponent>> _mapComponents;
        std::map<std::string, std::string> _mapComponentsType;

        std::map<std::string, C_InputTmp *> _tmpMapComponents;
        std::map<std::string, std::string> _tmpMapComponentsType;
        std::size_t _tick;
};

#endif /* !CIRCUIT_HPP_ */