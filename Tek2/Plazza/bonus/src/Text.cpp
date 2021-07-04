/*
** EPITECH PROJECT, 2021
** Text
** File description:
** file
*/

#include "Text.hpp"

sfml::Text::Text()
{
}

sfml::Text::Text(std::string string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos)
{
    if (!_font.loadFromFile(font_path)) {
        std::cerr << "Fail to load font : " << font_path << std::endl;
        exit (84);
    }
    _text.setFont(_font);
    _text.setString(string);
    _text.setCharacterSize(size);
    _text.setFillColor(color);
    _text.setStyle(style);
    _text.setPosition(pos);
    _string = string;
    _size = size;
    _color = color;
    _style = style;
    _pos = pos;
}

sfml::Text::Text(std::string string, std::string font_path, size_t size, sf::Color color, sf::Text::Style style, sf::Vector2f pos, sf::Vector2f window_size)
{
    if (!_font.loadFromFile(font_path)) {
        std::cerr << "Fail to load font : " << font_path << std::endl;
        exit (84);
    }
    _text.setFont(_font);
    _text.setString(string);
    _text.setCharacterSize(size);
    _text.setFillColor(color);
    _text.setStyle(style);
    sf::FloatRect textRect = _text.getLocalBounds();
    _text.setOrigin(textRect.width / 2, textRect.height / 2);
    _text.setPosition(sf::Vector2f(window_size.x / 2.0f, pos.y));
    _string = string;
    _size = size;
    _color = color;
    _style = style;
    _pos = pos;
}

sfml::Text::~Text()
{
}