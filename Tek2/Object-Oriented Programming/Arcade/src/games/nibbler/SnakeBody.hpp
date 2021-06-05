/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** SnakeBody
*/

#ifndef SNAKEBODY_HPP_
#define SNAKEBODY_HPP_

#include "UtilityClasses.hpp"
#include "Nibbler.hpp"


enum Direction;

    class SnakeBody {
        public:
            SnakeBody() {}
            SnakeBody(Vector2i, Direction, int, Content);
            ~SnakeBody();
            int getIndex() {return _index;}
            Content getContent() {return _content;}
            Direction getDirection() {return _direction;}
            Vector2i getPos() {return _pos;}
            void setNextPart(SnakeBody nexPart);
            void updateSnake(Direction);
            void updateSnake(SnakeBody);
            void setDirection(Direction);

        protected:
        private:

            void checkTurning();

            Direction _direction;
            Direction _tpmDirecion;
            Content _content = BODY;
            Vector2i _pos;
            int _index;
    };

#endif /* !SNAKEBODY_HPP_ */
