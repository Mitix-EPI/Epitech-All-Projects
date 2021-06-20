/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include <string>
#include <algorithm>
#include <iostream>
#include "IEncryptionMethod.hpp"

class Encryption {
    public:
        using method_ptr = void(IEncryptionMethod::*)(char);

        Encryption(IEncryptionMethod &, method_ptr);
        virtual ~Encryption();

        void operator()(char c);

        static void encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt);

        IEncryptionMethod *_method;
        method_ptr _func;

    protected:
    private:
};

#endif /* !ENCRYPTION_HPP_ */
