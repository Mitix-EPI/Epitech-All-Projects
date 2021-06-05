/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Vector2f
*/

#include "Vector2f.hpp"


//-------------------------------- Constructors ---------------------------------------//
Vector2f::Vector2f(float x, float y)
{
    this->_x = x;
    this->_y = y;
}

Vector2f::Vector2f()
{

}

//-------------------------------- Destructor -----------------------------------------//

Vector2f::~Vector2f()
{

}

//-------------------------------- Setters --------------------------------------------//

void Vector2f::setX(float x)
{
    this->_x = x;
}

void Vector2f::setY(float y)
{
    this->_y = y;
}

void Vector2f::set(float x, float y)
{
    this->_x = x;
    this->_y = y;
}

//-------------------------------- END ------------------------------------------------//
