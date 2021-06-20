/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "main_santa.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"

class IElf {
    public:
        IElf() {}
        virtual ~IElf() {}

        virtual Object *getObject(void) const = 0;
        virtual bool getComponent(ITable *table, IConveyorBelt *conveyor) = 0;
        virtual void trashUselessObjectOnTable(ITable *table, IConveyorBelt *conveyor, std::string type) = 0;

        virtual void makeGift(ITable *table, IConveyorBelt *conveyor) = 0; //send the elf to work
        virtual void openWrap(Wrap *wrap) = 0; // Elf can open wrap to see what's inside
        virtual void closeWrap(Wrap *wrap) = 0; // Elf can open wrap to see what's inside
        virtual void wrapThat(Wrap *wrap) = 0; //Elf can wrap => print"tuuuut tuuut tuut"
        virtual std::array<std::string, 11> lookTable(ITable *table) = 0; // Elf can look the table

        // Takes
        virtual void takeToy(Toy *toy) = 0; // Elf can pick up toy
        virtual void takeWrap(void) = 0; // Elf can take wrap; => print"whistles while working"
        virtual void takeObjectFromTable(ITable *table, std::string type) = 0; // Elf can take an object on the table
        virtual void takeObjectFromConveyorBelt(IConveyorBelt *conveyor) = 0; // Elf can take an object on the table

        // Puts
        virtual void putObjectInTable(ITable *table) = 0; // Elf can put object in table
        virtual void putObjectInConveyorBelt(IConveyorBelt *conveyor) = 0; // Elf can put object in conveyorbelt

        // Buttons
        virtual void pressInButton(IConveyorBelt *conveyor) = 0; // Elf can press the button IN
        virtual void pushOutButton(IConveyorBelt *conveyor) = 0; // Elf can press the button OUT
        virtual void trashButton(IConveyorBelt *conveyor) = 0; // Elf can delete the Object in the Conveyor pressing Trash Button

    protected:
        Object *_obj; // Object on the hands of the Elf
    private:
};

#endif /* !IELF_HPP_ */
