/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
#define ICONVEYORBELT_HPP_

#include "Object.hpp"

class IConveyorBelt {
    public:
        IConveyorBelt();
        virtual ~IConveyorBelt();

        virtual Object *getObject(void) const = 0;
        virtual bool getBool(void) const = 0;

        virtual IConveyorBelt *createConveyorBelt(void) = 0;

        virtual void in(void) = 0; // Add Wrap in Object
        virtual void out(void) = 0; // Send Object to Santa
        virtual Object *takeObject(void) = 0;
        virtual void putObject(Object *obj) = 0;
        virtual void trash(void) = 0;
    protected:
        bool _box;
        Object *_object; // Only One

    private:
};

#endif /* !ICONVEYORBELT_HPP_ */
