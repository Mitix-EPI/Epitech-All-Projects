/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ConveyorBeltRand
*/

#ifndef CONVEYORBELTRAND_HPP_
#define CONVEYORBELTRAND_HPP_

#include "PapaXmasConveyorBelt.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

class ConveyorBeltRand : public PapaXmasConveyorBelt {
    public:
        ConveyorBeltRand();
        ~ConveyorBeltRand();
        void out();
        void fillXml(std::string name) const;
    protected:
    private:
};

#endif /* !CONVEYORBELTRAND_HPP_ */
