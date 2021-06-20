/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : virtual public IEncryptionMethod {
    public:
        OneTime(const std::string &key);
        ~OneTime();

        void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset(void);

    protected:
        std::string _key;
        size_t _index;
    private:
};

#endif /* !ONETIME_HPP_ */
