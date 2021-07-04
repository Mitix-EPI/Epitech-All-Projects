/*
** EPITECH PROJECT, 2021
** graphical
** File description:
** graphical
*/

#include "Graphical.hpp"

Graphical::Graphical()
{
    _window.create(sf::VideoMode(1920, 1080), "Plazza Hut");
    _window.setFramerateLimit(60);
    _buffer = "";
    _bg = new sfml::Sprite("assets/pizza_bg.png", sf::IntRect(0, 0, 960, 568), sf::Vector2f(0, 0), sf::Vector2f(2, 2));
    _title = new sfml::Text("Plazza Hut", "assets/Signatria.ttf", 130, sf::Color::White, sf::Text::Style::Bold, sf::Vector2f(90, 40));
    _field = new sfml::Sprite("assets/field.png", sf::IntRect(0, 0, 370, 876), sf::Vector2f(50, 50), sf::Vector2f(1.6, 1.1));

    _type_title = new sfml::Text("Type", "assets/Signatria.ttf", 60, sf::Color::White, sf::Text::Style::Underlined, sf::Vector2f(150, 240), sf::Vector2f(692, 400));
    _typeField = new sfml::Sprite("assets/field_blue.png", sf::IntRect(0, 0, 445, 78), sf::Vector2f(192, 315), sf::Vector2f(0.7, 0.8));
    _typeNext = new sfml::Button("assets/button_right.png", "assets/button_right.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(523.5, 315), sf::Vector2f(0.8, 0.8));
    _typePrev = new sfml::Button("assets/button_left.png", "assets/button_left.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(102, 315), sf::Vector2f(0.8, 0.8));
    _typeValue = new sfml::Text("PizzaType", "assets/Asdonuts.ttf", 45, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(200, 335), sf::Vector2f(692, 400));
    _typeOpt.push_back("Margarita");
    _typeOpt.push_back("Regina");
    _typeOpt.push_back("Americana");
    _typeOpt.push_back("Fantasia");
    _typeIdx = 0;

    _size_title = new sfml::Text("Size", "assets/Signatria.ttf", 60, sf::Color::White, sf::Text::Style::Underlined, sf::Vector2f(150, 415), sf::Vector2f(692, 400));
    _sizeField = new sfml::Sprite("assets/field_blue.png", sf::IntRect(0, 0, 445, 78), sf::Vector2f(192, 490), sf::Vector2f(0.7, 0.8));
    _sizeNext = new sfml::Button("assets/button_right.png", "assets/button_right.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(523.5, 490), sf::Vector2f(0.8, 0.8));
    _sizePrev = new sfml::Button("assets/button_left.png", "assets/button_left.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(102, 490), sf::Vector2f(0.8, 0.8));
    _sizeValue = new sfml::Text("PizzaSize", "assets/Asdonuts.ttf", 45, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(200, 510), sf::Vector2f(692, 400));
    _sizeOpt.push_back("S");
    _sizeOpt.push_back("M");
    _sizeOpt.push_back("L");
    _sizeOpt.push_back("XL");
    _sizeOpt.push_back("XXL");
    _sizeIdx = 0;

    _quantity_title = new sfml::Text("Quantity", "assets/Signatria.ttf", 60, sf::Color::White, sf::Text::Style::Underlined, sf::Vector2f(150, 590), sf::Vector2f(692, 400));
    _quantityField = new sfml::Sprite("assets/field_blue.png", sf::IntRect(0, 0, 445, 78), sf::Vector2f(192, 665), sf::Vector2f(0.7, 0.8));
    _quantityNext = new sfml::Button("assets/button_right.png", "assets/button_right.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(523.5, 665), sf::Vector2f(0.8, 0.8));
    _quantityPrev = new sfml::Button("assets/button_left.png", "assets/button_left.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(102, 665), sf::Vector2f(0.8, 0.8));
    _quantityValue = new sfml::Text("PizzaQuantity", "assets/Asdonuts.ttf", 45, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(200, 685), sf::Vector2f(692, 400));
    _quantityOpt = 1;

    _commandButton = new sfml::Button("assets/command_button.png", "assets/command_button.png", sf::IntRect(0, 0, 359, 83), sf::Vector2f(214, 820), sf::Vector2f(0.75, 1.0));
    _commandText = new sfml::Text("Order", "assets/Asdonuts.ttf", 50, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(200, 845), sf::Vector2f(692, 400));

    _board = new sfml::Sprite("assets/board.jpg", sf::IntRect(0, 0, 849, 1125), sf::Vector2f(680, 280), sf::Vector2f(1.40, 0.65));
    _board->_sprite.setColor(sf::Color(255, 255, 255, 245));
    for (int i = 0; i < LOG_SIZE; i++)
        _logs.push_back(new sfml::Text("Log " + std::to_string(i), "assets/horrendo.ttf", 35, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(820, 390 + i * 50)));

    _kitchen_logo = new sfml::Sprite("assets/kitchen.png", sf::IntRect(0, 0, 270, 270), sf::Vector2f(700, 50), sf::Vector2f(0.8, 0.8));
    _kitchen_nbr = 0;
    _kitchen_txt = new sfml::Text("X " + std::to_string(_kitchen_nbr), "assets/Lemon Friday.ttf", 100, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(900, 100));

    _quitBtn = new sfml::Button("assets/croix.png", "assets/croix.png", sf::IntRect(0, 0, 425, 425), sf::Vector2f(1700, 60), sf::Vector2f(0.2, 0.2));
}

Graphical::~Graphical()
{
    delete(_bg);
    delete(_title);
    delete(_field);
    delete(_type_title);
    delete(_size_title);
    delete(_quantity_title);

    delete(_typeField);
    delete(_typeValue);
    delete(_typeNext);
    delete(_typePrev);

    delete(_sizeField);
    delete(_sizeValue);
    delete(_sizeNext);
    delete(_sizePrev);

    delete(_quantityField);
    delete(_quantityValue);
    delete(_quantityNext);
    delete(_quantityPrev);

    delete(_commandButton);
    delete(_commandText);

    for (int i = 0; i < LOG_SIZE; i++)
        delete(_logs.at(i));
    delete(_board);

    delete(_kitchen_logo);
    delete(_kitchen_txt);
    delete(_quitBtn);
}

void Graphical::input_management(void)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
        if (_event.type == sf::Event::TextEntered)
            _keyboardInput = _event.text.unicode;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _clock.getElapsedTime().asMilliseconds() > 120)
        {
            _clock.restart();
            _mousePosition = sf::Mouse::getPosition(_window);
            if (_typeNext->checkClick(_mousePosition)) {
                if (_typeIdx + 1 >= _typeOpt.size())
                    _typeIdx = 0;
                else
                    _typeIdx++;
            }
            if (_typePrev->checkClick(_mousePosition)) {
                if (_typeIdx == 0)
                    _typeIdx = _typeOpt.size() - 1;
                else
                    _typeIdx--;
            }

            if (_sizeNext->checkClick(_mousePosition)) {
                if (_sizeIdx + 1 >= _sizeOpt.size())
                    _sizeIdx = 0;
                else
                    _sizeIdx++;
            }
            if (_sizePrev->checkClick(_mousePosition)) {
                if (_sizeIdx == 0)
                    _sizeIdx = _sizeOpt.size() - 1;
                else
                    _sizeIdx--;
            }

            if (_quantityNext->checkClick(_mousePosition))
                _quantityOpt++;
            if (_quantityPrev->checkClick(_mousePosition))
                if (_quantityOpt > 1)
                    _quantityOpt--;
            if (_commandButton->checkClick(_mousePosition)) {
                _buffer = _typeOpt.at(_typeIdx) + " " + _sizeOpt.at(_sizeIdx) + " x" + std::to_string(_quantityOpt) + "\r\n";
                Logfile::logFile(_buffer);
            }
            if (_quitBtn->checkClick(_mousePosition))
                _window.close();
        }
    }
}

void Graphical::draw(void)
{
    _window.draw(_bg->_sprite);
    _window.draw(_field->_sprite);
    _window.draw(_title->_text);

    _window.draw(_type_title->_text);
    _window.draw(_typeField->_sprite);
    _window.draw(_typeValue->_text);
    _window.draw(_typeNext->_button->_sprite);
    _window.draw(_typePrev->_button->_sprite);

    _window.draw(_size_title->_text);
    _window.draw(_sizeField->_sprite);
    _window.draw(_sizeValue->_text);
    _window.draw(_sizeNext->_button->_sprite);
    _window.draw(_sizePrev->_button->_sprite);

    _window.draw(_quantity_title->_text);
    _window.draw(_quantityField->_sprite);
    _window.draw(_quantityValue->_text);
    _window.draw(_quantityNext->_button->_sprite);
    _window.draw(_quantityPrev->_button->_sprite);

    _window.draw(_commandButton->_button->_sprite);
    _window.draw(_commandText->_text);

    _window.draw(_board->_sprite);
    for (int i = 0; i < LOG_SIZE; i++)
        _window.draw(_logs.at(i)->_text);

    _window.draw(_kitchen_logo->_sprite);
    _window.draw(_kitchen_txt->_text);

    _window.draw(_quitBtn->_button->_sprite);
}

void Graphical::update(std::vector<std::string> logs, size_t kitchen_nbr)
{
    _typeValue->_string = _typeOpt.at(_typeIdx);
    _typeValue->_text.setString(_typeValue->_string);
    _typeValue->_text.setOrigin(_typeValue->_text.getLocalBounds().width / 2, _typeValue->_text.getLocalBounds().height / 2);

    _sizeValue->_string = _sizeOpt.at(_sizeIdx);
    _sizeValue->_text.setString(_sizeValue->_string);
    _sizeValue->_text.setOrigin(_sizeValue->_text.getLocalBounds().width / 2, _sizeValue->_text.getLocalBounds().height / 2);

    _quantityValue->_string = std::to_string(_quantityOpt);
    _quantityValue->_text.setString(_quantityValue->_string);
    _quantityValue->_text.setOrigin(_quantityValue->_text.getLocalBounds().width / 2, _quantityValue->_text.getLocalBounds().height / 2);

    for (int i = 0; i < LOG_SIZE; i++) {
        _logs.at(i)->_string.assign(logs.at(i));
        _logs.at(i)->_text.setString(_logs.at(i)->_string);
    }

    _kitchen_nbr = kitchen_nbr;
    _kitchen_txt->_string = "X " + std::to_string(_kitchen_nbr);
    _kitchen_txt->_text.setString(_kitchen_txt->_string);
}

void Graphical::loop(std::vector<std::string> logs, size_t kitchen_nbr)
{
    if (_window.isOpen()) {
        input_management();
        _window.clear(sf::Color::Black);
        draw();
        update(logs, kitchen_nbr);
        _window.display();
    } else
        exit(0);
}