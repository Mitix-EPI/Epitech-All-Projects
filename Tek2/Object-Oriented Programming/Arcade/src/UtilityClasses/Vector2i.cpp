/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Vector2i
*/

#include "Vector2i.hpp"


//-------------------------------- Constructors ---------------------------------------//
Vector2i::Vector2i(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

Vector2i::Vector2i()
{

}

//-------------------------------- Destructor -----------------------------------------//

Vector2i::~Vector2i()
{

}

//-------------------------------- Setters --------------------------------------------//

void Vector2i::setX(int x)
{
    this->_x = x;
}

void Vector2i::setY(int y)
{
    this->_y = y;
}

void Vector2i::set(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void Vector2i::set(Vector2i vec)
{
    this->_x = vec.getX();
    this->_y = vec.getY();
}

//-------------------------------- Adders --------------------------------------------//

void Vector2i::addX(int x)
{
    this->_x += x;
}

void Vector2i::addY(int y)
{
    this->_y += y;
}
//-------------------------------- END ------------------------------------------------//

bool Vector2i::operator==(Vector2i vec)
{
    return (vec._x == this->_x && vec._y == this->_y);
}

bool Vector2i::operator!=(Vector2i vec)
{
    return (vec._x != this->_x || vec._y != this->_y);
}