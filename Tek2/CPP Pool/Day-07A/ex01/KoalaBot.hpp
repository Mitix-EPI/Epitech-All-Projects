/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

class KoalaBot {
    public:
        KoalaBot(std::string const &_serial = "Bob-01");
        ~KoalaBot();

        void setParts(Arms &arms);
        void setParts(Legs &legs);
        void setParts(Head &head);

        void swapParts(Arms &arms);
        void swapParts(Head &head);
        void swapParts(Legs &legs);

        void informations(void) const;
        bool status(void) const;


    protected:
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string const &_serial;
};

#endif /* !KOALABOT_HPP_ */
