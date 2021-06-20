/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** Ratatouille
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_

#include <iostream>
#include <string>
#include <sstream>

class Ratatouille {
    public:
        Ratatouille();
        Ratatouille(Ratatouille const &other);
        Ratatouille &operator=(const Ratatouille &other);
        ~Ratatouille();

        Ratatouille &addVegetable(unsigned char veg) { _tmp << veg; return *this; }
        Ratatouille &addCondiment(unsigned int cond) { _tmp << cond; return *this; }
        Ratatouille &addSpice(double spice) { _tmp << spice; return *this; }
        Ratatouille &addSauce(const std::string &sauce) { _tmp << sauce; return *this; }

        std::string kooc() { return _tmp.str(); }
        std::ostringstream _tmp;
    protected:
    private:
};

#endif /* !RATATOUILLE_HPP_ */
