/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <string>
#include <iostream>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();

        void ping() const;
        void locateSquad() const;

    protected:
    private:
        int _x;
        int _y;
        const int m_serial;
        KreogCom *_next;
};

#endif /* !KREOGCOM_HPP_ */
