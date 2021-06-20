/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF_HPP_
#define PAPAXMASELF_HPP_

#include "IElf.hpp"

class PapaXmasElf : public IElf {
    public:
        PapaXmasElf();
        ~PapaXmasElf();

        // Getters
        Object *getObject(void) const { return this->_obj; }
        bool getComponent(ITable *table, IConveyorBelt *conveyor);

        void makeGift(ITable *table, IConveyorBelt *conveyor); //send the elf to work
        void openWrap(Wrap *wrap); // Elf can open wrap to see what's inside
        void closeWrap(Wrap *wrap); // Elf can open wrap to see what's inside
        void wrapThat(Wrap *wrap); //Elf can wrap => print"tuuuut tuuut tuut"
        std::array<std::string, 11> lookTable(ITable *table); // Elf can look the table
        void trashUselessObjectOnTable(ITable *table, IConveyorBelt *conveyor, std::string type);
        void trashButton(IConveyorBelt *conveyor);

        // Takes
        void takeToy(Toy *toy); // Elf can pick up toy
        void takeWrap(void); // Elf can take wrap; => print"whistles while working"
        void takeObjectFromTable(ITable *table, std::string type); // Elf can take an object on the table
        void takeObjectFromConveyorBelt(IConveyorBelt *conveyor); // Elf can put object in conveyorbelt

        // Puts
        void putObjectInTable(ITable *table); // Elf can put object in table
        void putObjectInConveyorBelt(IConveyorBelt *conveyor); // Elf can put object in conveyorbelt

        // Buttons
        void pressInButton(IConveyorBelt *conveyor); // Elf can press the button IN
        void pushOutButton(IConveyorBelt *conveyor); // Elf can press the button OUT

    protected:
    private:
};

#endif /* !PAPAXMASELF_HPP_ */
