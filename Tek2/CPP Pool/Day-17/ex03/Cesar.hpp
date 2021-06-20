/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class Cesar : virtual public IEncryptionMethod {
    public:
        Cesar();
        ~Cesar();

        // Encode the given character, and display it.
        void encryptChar(char plainchar);
        // Decide the given character and display it.
        void decryptChar(char cipherChar);
        // Reset the internal values to their initial state.
        void reset(void);

    protected:
        int _interval;
    private:
};

#endif /* !CESAR_HPP_ */
