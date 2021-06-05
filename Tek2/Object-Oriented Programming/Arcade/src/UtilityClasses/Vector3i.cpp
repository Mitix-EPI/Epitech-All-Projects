/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Vector3i
*/

#include "Vector3i.hpp"


//-------------------------------- Constructors ---------------------------------------//
Vector3i::Vector3i(int x, int y, int z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Vector3i::Vector3i()
{

}

//-------------------------------- Destructor -----------------------------------------//

Vector3i::~Vector3i()
{

}

//-------------------------------- Setters --------------------------------------------//

void Vector3i::setX(int x)
{
    this->_x = x;
}

void Vector3i::setY(int y)
{
    this->_y = y;
}

void Vector3i::set(int x, int y, int z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

//-------------------------------- END ------------------------------------------------//
