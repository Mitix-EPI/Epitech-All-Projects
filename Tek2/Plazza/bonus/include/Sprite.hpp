/*
** EPITECH PROJECT, 2021
** Sprite
** File description:
** Header file
*/

#ifndef SFML_SPRITE_H_
#define SFML_SPRITE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace sfml {
    class Sprite {
        public:
            Sprite() {};
            Sprite(std::string texture_filepath, sf::IntRect rect, sf::Vector2f pos, sf::Vector2f scale);
            ~Sprite();
            sf::Sprite _sprite;
            sf::Texture _texture;
            sf::IntRect _rect;
            sf::Vector2f _pos;
            sf::Vector2f _scale;
            std::string _filepath;

        protected:
        private:
    };
}

#endif /* !SFML_SPRITE_H_ */