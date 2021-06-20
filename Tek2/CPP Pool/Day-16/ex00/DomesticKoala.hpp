/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include "KoalaAction.hpp"
#include <string>
#include <iostream>
#include <vector>

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &);
        DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala &);
        ~DomesticKoala();

        using methodPointer_t = void (KoalaAction::*)(const std::string &);

        // Retrieves a vector containing all the member function pointers
        const std::vector<methodPointer_t> *getActions() const { return &this->_actions; };

        // Sets a member function pointer , linking the character (the command ) to the
        // pointer (the action ).
        void learnAction(unsigned char command, methodPointer_t action);

        // Deletes the command
        void unlearnAction(unsigned char command);

        // Executes the action linked to the given command . The string is the parameter
        // given to the member function .
        void doAction(unsigned char command, const std::string &param);

        // Affects a new KoalaAction class to the domestic Koala .
        // This erases the pointers table .
        void setKoalaAction(KoalaAction &);

        std::vector<methodPointer_t> _actions;
        std::vector<unsigned char> _chars;

        KoalaAction _koalaAction;

    protected:
    private:
};

#endif /* !DOMESTICKOALA_HPP_ */
