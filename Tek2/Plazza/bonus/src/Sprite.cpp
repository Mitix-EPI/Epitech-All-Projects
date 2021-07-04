/*
** EPITECH PROJECT, 2021
** Sprite
** File description:
** file
*/

#include "Sprite.hpp"

sfml::Sprite::Sprite(std::string texture_filepath, sf::IntRect rect, sf::Vector2f pos, sf::Vector2f scale)
{
    if (!_texture.loadFromFile(texture_filepath)) {
        std::cerr << "Fail to load texture : " << texture_filepath << std::endl;
        exit (84);
    }
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _sprite.setPosition(pos);
    _sprite.setScale(scale);
    _rect = rect;
    _pos = pos;
    _scale = scale;
    _filepath = texture_filepath;
}

sfml::Sprite::~Sprite()
{
}