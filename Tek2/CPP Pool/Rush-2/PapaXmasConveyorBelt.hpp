/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** PapaXmasConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
#define PAPAXMASCONVEYORBELT_HPP_

#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt {
    public:
        PapaXmasConveyorBelt();
        ~PapaXmasConveyorBelt();

        IConveyorBelt *createConveyorBelt(void);
        Object*getObject(void) const { return this->_object; };
        bool getBool(void) const { return this->_box; };
        void in(void);
        void out(void);
        Object *takeObject(void);
        void putObject(Object *obj);
        void trash();
    protected:
    private:
};

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
