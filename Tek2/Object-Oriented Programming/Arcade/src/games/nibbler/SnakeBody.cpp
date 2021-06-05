/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** SnakeBody
*/

#include "SnakeBody.hpp"

SnakeBody::SnakeBody(Vector2i pos, Direction direction, int index, Content content)
{
    this->_pos = pos;
    this->_direction = direction;
    this->_index = index;
    this->_content = content;
    this->_tpmDirecion = direction;
}

SnakeBody::~SnakeBody()
{
}

void SnakeBody::updateSnake(Direction direction)
{
    int x = this->_pos.getX();
    int y = this->_pos.getY();
    switch (direction) {
        case UP:
            y -= 1;
            this->_direction = UP;
            break;
        case DOWN:
            y += 1;
            this->_direction = DOWN;
            break;
        case LEFT:
            x -= 1;
            this->_direction = LEFT;
            break;
        case RIGHT:
            x += 1;
            this->_direction = RIGHT;
            break;
        default:
            break;
    }
    this->_pos.set(x, y);
}

void SnakeBody::updateSnake(SnakeBody other)
{
    this->_direction = other.getDirection();
    this->_pos = other.getPos();
}

void SnakeBody::setDirection(Direction dir)
{
    this->_direction = dir;
}