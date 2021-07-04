/*
** EPITECH PROJECT, 2021
** Input
** File description:
** header file
*/

#ifndef SFML_INPUT_H_
#define SFML_INPUT_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Text.hpp"

namespace sfml {
    class Input {
        public:
            Input(std::string string, std::string input_string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos);
            Input(std::string text_string, std::string input_string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos, sf::Vector2f window_size);
            Input();
            ~Input();
            sfml::Text *_playerText;
            std::string _playerInput;

        protected:
        private:
    };
}

#endif /* !SFML_INPUT_H_ */