/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include "UtilityClasses.hpp"

namespace object {
    enum direction {
        RIGHT,
        LEFT,
        UP,
        DOWN,
    };

    typedef struct Sprite_s {
        std::string _filePath = "";
        direction _direction = RIGHT;
        Vector2i _mult;
        Vector2i _extra;
        Vector2i _rectSize;
        Vector2i _sizeSquare;
        Vector2i _scale;
        char _charNcurse = 'O';
    } Sprite_t;

    class Object {
        public:
            //Constructor
            Object() {};

            //Destructor
            ~Object() {};

            //Getters
            bool isWalkable() { return this->_isWalkable; }
            bool isActive() { return this->_active; }
            int getContent() { return this->_content; }
            Vector2i getPos() { return this->_coords; }
            Vector2i getSpawn() { return this->_spawn; }
            Vector3i getColor() { return this->_color; }
            std::size_t getSize() { return this->_size; }
            std::size_t getVelocity() { return this->_velocity; }
            Sprite_t getSprite() { return this->_sprite; }
            int getLevel() { return this->_level; }

            //Setters
            void setPos(Vector2i coord) { this->_coords = coord; }
            void setSpawn(Vector2i spawn) { this->_spawn = spawn; }
            void setContent(int content) { this->_content = content; }
            void setColor(Vector3i color) { this->_color = color; }
            void setActive(bool active) { this->_isWalkable = active; }
            void setWalkable(bool walkable) { this->_isWalkable = walkable; }
            void setVelocity(float velocity) { this->_velocity = velocity; }
            void setSprite(Sprite_t sprite) { this->_sprite = sprite; }
            void setLevel(int level) { this->_level = level; }



        protected:
            bool _isWalkable;
            Vector2i _coords;
            Vector2i _spawn;
            int _content;
            bool _active;
            Vector3i _color;
            std::size_t _size;
            float _velocity;
            Sprite_t _sprite;
            int _level;
        private:
    };
};

#endif /* !OBJECT_HPP_ */
