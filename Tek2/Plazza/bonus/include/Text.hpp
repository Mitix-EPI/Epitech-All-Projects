/*
** EPITECH PROJECT, 2021
** Text
** File description:
** header file
*/

#ifndef SFML_TEXT_H_
#define SFML_TEXT_H_

#include <SFML/Graphics.hpp>
#include <iostream>

namespace sfml {
    class Text {
        public:
            Text();
            Text(std::string string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos);
            Text(std::string string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos, sf::Vector2f window_size);
            ~Text();
            sf::Text _text;
            sf::Font _font;
            std::string _string;
            size_t _size;
            sf::Color _color;
            sf::Text::Style _style;
            sf::Vector2f _pos;
        protected:
        private:
    };
}

#endif /* !SFML_TEXT_H_ */