/*
** EPITECH PROJECT, 2021
** graphical
** File description:
** graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#define LOG_SIZE 10

#include <SFML/Graphics.hpp>
#include "Sprite.hpp"
#include "Text.hpp"
#include "Input.hpp"
#include "Button.hpp"
#include "DisplayLog.hpp"
#include "Logfile.hpp"

class Graphical {
    public:
        Graphical();
        ~Graphical();
        void loop(std::vector<std::string> logs, size_t kitchen_nbr);
        void draw(void);
        void update(std::vector<std::string> logs, size_t kitchen_nbr);
        void input_management(void);
        std::string _buffer;

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock _clock;

        sf::Vector2i _mousePosition;
        char _keyboardInput;

        sfml::Sprite *_bg;

        sfml::Text *_title;
        sfml::Sprite * _field;
        sfml::Text *_type_title;
        sfml::Text *_size_title;
        sfml::Text *_quantity_title;

        sfml::Sprite * _typeField;
        sfml::Button *_typeNext;
        sfml::Button *_typePrev;
        sfml::Text *_typeValue;
        std::vector<std::string> _typeOpt;
        size_t _typeIdx;

        sfml::Sprite * _sizeField;
        sfml::Button *_sizeNext;
        sfml::Button *_sizePrev;
        sfml::Text *_sizeValue;
        std::vector<std::string> _sizeOpt;
        size_t _sizeIdx;;

        sfml::Sprite * _quantityField;
        sfml::Button *_quantityNext;
        sfml::Button *_quantityPrev;
        sfml::Text *_quantityValue;
        size_t _quantityOpt;

        sfml::Button *_commandButton;
        sfml::Text *_commandText;
        std::vector<sfml::Text *> _logs;
        sfml::Sprite *_board;

        sfml::Sprite *_kitchen_logo;
        sfml::Text *_kitchen_txt;
        size_t _kitchen_nbr;

        sfml::Button *_quitBtn;
};

#endif /* !GRAPHICAL_HPP_ */