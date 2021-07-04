/*
** EPITECH PROJECT, 2021
** Input
** File description:
** file
*/

#include "Input.hpp"

sfml::Input::Input(std::string text_string, std::string input_string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos)
{
    if (!_playerText->_font.loadFromFile(font_path)) {
        std::cerr << "Fail to load font : " << font_path << std::endl;
        exit (84);
    }
    _playerText = new sfml::Text(text_string, font_path, size, color, style, pos);
    _playerInput = input_string;
}

sfml::Input::Input(std::string text_string, std::string input_string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos, sf::Vector2f window_size)
{
    if (!_playerText->_font.loadFromFile(font_path)) {
        std::cerr << "Fail to load font : " << font_path << std::endl;
        exit (84);
    }
    _playerText = new sfml::Text(text_string, font_path, size, color, style, pos, window_size);
    _playerInput = input_string;
}

sfml::Input::Input()
{
}

sfml::Input::~Input()
{
    delete (_playerText);
}