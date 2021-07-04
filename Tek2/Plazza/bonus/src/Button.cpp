/*
** EPITECH PROJECT, 2021
** Button
** File description:
** file
*/

#include "Button.hpp"

sfml::Button::Button(std::string texture_filepath_idle, std::string texture_filepath_clicked, sf::IntRect rect, sf::Vector2f pos, sf::Vector2f scale)
{
    if (!_idle_texture.loadFromFile(texture_filepath_idle)) {
        std::cerr << "Fail to load texture : " << texture_filepath_idle << std::endl;
        exit (84);
    }
    if (!_clicked_texture.loadFromFile(texture_filepath_clicked)) {
        std::cerr << "Fail to load texture : " << texture_filepath_clicked << std::endl;
        exit (84);
    }
    _button = new sfml::Sprite(texture_filepath_idle, rect, pos, scale);
    _state = IDLE;
}

sfml::Button::~Button()
{
    delete (_button);
}

bool sfml::Button::checkClick (sf::Vector2i mousePos)
{
    if (mousePos.x > _button->_pos.x && mousePos.x < (_button->_pos.x + _button->_rect.width))
        if(mousePos.y > _button->_pos.y && mousePos.y < (_button->_pos.y + _button->_rect.height))
                return true;
    return false;
}