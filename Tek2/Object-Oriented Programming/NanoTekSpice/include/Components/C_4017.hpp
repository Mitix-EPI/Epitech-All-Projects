/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4017
*/

#ifndef C_4017_HPP_
#define C_4017_HPP_

#include <unordered_map>
#include <functional>
#include <utility> // std::pair
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Component.hpp"
#include "IComponent.hpp"

class C_4017 : public Component {
    public:
        C_4017();
        ~C_4017();

        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate compute(std::size_t pin) override;
        void dump(void) const override;

        nts::Tristate computeInput(std::size_t pin) const;
        nts::Tristate computeOutput(std::size_t pin);
        nts::Tristate computeVSS(std::size_t pin) const;
        nts::Tristate computeVDD(std::size_t pin) const;
        void setOutputs(void);
        long unsigned int calcLinkedOutputs(void) const;

        void reset(void);
        void progress(void);

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;
        std::unordered_map<std::size_t, nts::Tristate> _outputs;
        std::size_t _increment;
        nts::Tristate _metamorph;

        const std::vector<std::size_t> _possibleOutputsIndex = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11};
};

#endif /* !C_4017_HPP_ */
