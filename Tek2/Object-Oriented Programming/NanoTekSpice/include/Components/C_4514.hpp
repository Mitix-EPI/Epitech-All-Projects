/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4514
*/

#ifndef C_4514_HPP_
#define C_4514_HPP_

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

class C_4514 : public Component {
    public:
        C_4514();
        ~C_4514();

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
        bool isNotUndefined(void) const;

        void reset(void);
        void progress(void);

    private:
        std::unordered_map<std::size_t, std::function<nts::Tristate(std::size_t pin)>> _map;
        nts::Tristate _metamorph;

        const std::vector<std::size_t> _possibleOutputsIndex = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};

        std::unordered_map<std::size_t, nts::Tristate> _outputs;
};

#endif /* !C_4514_HPP_ */
