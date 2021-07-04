/*
** EPITECH PROJECT, 2021
** Button
** File description:
** Header file
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

namespace sfml {
    typedef enum button_state {
        IDLE,
        CLICKED,
        OVERLAY
    }button_state;

    class Button {
        public:
            Button() {};
            Button(std::string texture_filepath_idle, std::string texture_filepath_clicked, sf::IntRect rect, sf::Vector2f pos, sf::Vector2f scale);
            ~Button();
            bool checkClick(sf::Vector2i);
            sfml::Sprite *_button;
            sf::Texture _clicked_texture;
            sf::Texture _idle_texture;
            button_state _state;
        private:
    };
}

#endif /* !BUTTON_H_ */