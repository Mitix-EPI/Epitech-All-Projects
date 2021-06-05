/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** sfml
*/
#include <iostream>
#include "sfml.hpp"
#include "UtilityClasses.hpp"

sfmlDisplay::sfml::sfml()
{
    this->_allGames.push_back("nibbler");
    this->_allGames.push_back("pacman");
    this->_allGames.push_back("qix");
    this->_allGames.push_back("centipede");
    this->_allGames.push_back("solarfox");
    this->_allGraphics.push_back("ncurses");
    this->_allGraphics.push_back("sdl2");
    this->_allGraphics.push_back("ndk++");
    this->_allGraphics.push_back("aalib");
    this->_allGraphics.push_back("libcaca");
    this->_allGraphics.push_back("allegro5");
    this->_allGraphics.push_back("xlib");
    this->_allGraphics.push_back("gtk+");
    this->_allGraphics.push_back("irrlicht");
    this->_allGraphics.push_back("opengl");
    this->_allGraphics.push_back("vulkan");
    this->_allGraphics.push_back("arcade_qt5");
    this->_allGraphics.push_back("sfml");
    this->_inputName = false;
    this->_restartEvent = 0;
    this->_time = this->_clock.restart();
    this->_time2 = this->_clock2.restart();
    this->_game = "";
    this->_lib = "";
    this->_print = false;
    this->_play = false;
}

void sfmlDisplay::sfml::changeGame()
{
    this->_sprites = {};
    this->_textures = {};
}

sfmlDisplay::sfml::~sfml()
{
}

void sfmlDisplay::sfml::setText(sfmlDisplay::text_t text, bool is_bold)
{
    this->_texts[text.name].setFont(this->_menuText);
    this->_texts[text.name].setCharacterSize(text.charSize);
    this->_texts[text.name].setFillColor(text.color);
    this->_texts[text.name].setString(text.print);
    sf::FloatRect textRect = this->_texts[text.name].getLocalBounds();
    this->_texts[text.name].setPosition(sf::Vector2f(text.width - textRect.width/2.0f, text.height - textRect.height/2.0f));
    if (is_bold)
        this->_texts[text.name].setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void sfmlDisplay::sfml::setSquare(std::string name, sf::Color color, int squareType)
{
    int width = this->_window->getSize().x;
    int height = this->_window->getSize().y;
    this->_squares[name].setSize(sf::Vector2f(width/3.6f, height/1.25f));
    this->_squares[name].setPosition(sf::Vector2f(width/36.0f + squareType * (width/3.6f + (width/36.0f)*2), height/6.66f));
    this->_squares[name].setFillColor(sf::Color(201, 201, 201, 0.69));
    this->_squares[name].setOutlineColor(color);
    this->_squares[name].setOutlineThickness(2.0f);
}

void sfmlDisplay::sfml::setSprite(std::string name, std::string path)
{
    if (!this->_textures[name].loadFromFile(path))
        std::cerr << "Can't load image : " << path << std::endl;
    this->_sprites[name].setTexture(this->_textures[name]);
}

void sfmlDisplay::sfml::setGames()
{
    std::srand(std::time(nullptr));
    int width = this->_window->getSize().x;
    int height = this->_window->getSize().y;
    int rand = 0;
    sf::Color colors[4] = {sf::Color(255, 255, 255, 100), sf::Color(0, 0, 255, 100), sf::Color(255, 0, 255, 100), sf::Color(0, 255, 255, 100)};
    for (long unsigned int i = 0; i < this->_allGames.size(); i++) {
        sfmlDisplay::text_t gamesText;
        gamesText.name = this->_allGames[i];
        for (long unsigned int j = 0; j < this->_allGames[i].size(); j++)
            gamesText.print.push_back(std::toupper(this->_allGames[i][j]));
        gamesText.charSize = 50;
        rand = std::rand() % 5;
        gamesText.color = (this->_allGames[i] == "nibbler") ? sf::Color(0, 255, 0, 100) : (this->_allGames[i] == "pacman") ? sf::Color(255, 255, 0, 100) : colors[rand];
        gamesText.width = width/2.0f;
        gamesText.height = height/6.66f + (((height/1.25f) / (this->_allGames.size() + 1)) * (i + 1));
        setText(gamesText);
    }
}

void sfmlDisplay::sfml::setGraphic()
{
    std::srand(std::time(nullptr));
    int width = this->_window->getSize().x;
    int height = this->_window->getSize().y;
    int rand = 0;
    sf::Color colors[6] = {sf::Color(255, 255, 255, 100), sf::Color(255, 255, 0, 100), sf::Color(0, 0, 255, 100), sf::Color(0, 255, 0, 100), sf::Color(255, 0, 255, 100), sf::Color(0, 255, 255, 100)};
    for (long unsigned int i = 0; i < this->_allGraphics.size(); i++) {
        sfmlDisplay::text_t graphicsText;
        graphicsText.name = this->_allGraphics[i];
        for (long unsigned int j = 0; j < this->_allGraphics[i].size(); j++)
            graphicsText.print.push_back(std::toupper(this->_allGraphics[i][j]));
        graphicsText.charSize = 50;
        rand = std::rand() % 5;
        graphicsText.color = colors[rand];
        graphicsText.width = width/6.0f;
        graphicsText.height = height/6.66f + (((height/1.25f) / (this->_allGraphics.size() + 1)) * (i + 1));
        setText(graphicsText);
    }
}

void sfmlDisplay::sfml::setLeaderboard(std::string name)
{
    std::srand(std::time(nullptr));
    this->_leader[name] = getTopPlayers(name);
    if (this->_leader[name].empty())
        return;
    int width = this->_window->getSize().x;
    int height = this->_window->getSize().y;
    int rand = 0;
    sf::Color colors[6] = {sf::Color(255, 255, 255, 255), sf::Color(255, 255, 0, 255), sf::Color(0, 0, 255, 255), sf::Color(0, 255, 0, 255), sf::Color(255, 0, 255, 255), sf::Color(0, 255, 255, 255)};
    for (long unsigned int i = 0; i < this->_leader[name].size() && i < 10; i++) {
        sfmlDisplay::text_t topPlayersText;
        topPlayersText.name = name + "-" + std::to_string(i);
        topPlayersText.print = std::get<0>(this->_leader[name][i]) + ": " + std::to_string(std::get<1>(this->_leader[name][i]));
        topPlayersText.charSize = 50;
        rand = std::rand() % 5;
        topPlayersText.color = colors[rand];
        topPlayersText.width = (width/6.0f) * 5.0f;
        topPlayersText.height = height/6.66f + (((height/1.25f) / (((this->_leader[name].size() > 10) ? 10 : this->_leader[name].size()) + 1)) * (i + 1));
        setText(topPlayersText);
    }
}

void sfmlDisplay::sfml::open()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade SFML");
    if (this->_cursor.loadFromSystem(sf::Cursor::Cross))
        this->_window->setMouseCursor(this->_cursor);
    if (!this->_menuText.loadFromFile("assets/arcade_menu.ttf"))
        throw error(std::cerr, "Unable to open font file");
    int width = this->_window->getSize().x;
    int height = this->_window->getSize().y;
    sfmlDisplay::text_t arcade_menu = {.name = "arcade_menu", .print = "ARCADE", .color = sf::Color::White,
    .charSize = 100, .width = width/2.0f, .height = height/25.0f};
    setText(arcade_menu);
    sfmlDisplay::text_t leaderboard = {.name = "leaderboard", .print = "LEADERBOARD", .color = sf::Color::White,
    .charSize = 60, .width = ((width/6.0f) * 5.0f), .height = height/6.0f};
    setText(leaderboard, true);
    sfmlDisplay::text_t gamesHead = {.name = "games", .print = "GAMES", .color = sf::Color::White,
    .charSize = 60, .width = width/2.0f, .height = height/6.0f};
    setText(gamesHead, true);
    sfmlDisplay::text_t graphicsHead = {.name = "graphics", .print = "GRAPHICS", .color = sf::Color::White,
    .charSize = 60, .width = width/6.0f, .height = height/6.0f};
    setText(graphicsHead, true);
    sfmlDisplay::text_t playerNameHead = {.name = "player", .print = "PLAYER", .color = sf::Color::White,
    .charSize = 100, .width = width/2.0f, .height = height/2.6f};
    setText(playerNameHead);
    sfmlDisplay::text_t playerName = {.name = "name", .print = "---", .color = sf::Color::White,
    .charSize = 100, .width = width/2.0f, .height = height/2.0f};
    setText(playerName);
    sf::Color color(255, 255, 255, 1);
    sfmlDisplay::text_t nameHead = {.name = "play", .print = "PLAY", .color = sf::Color(255, 255, 255, 100),
    .charSize = 80, .width = (width/6.0f) * 4.4f, .height = height/18.0f};
    setText(nameHead);
    sfmlDisplay::text_t namePrint = {.name = "namePrint", .print = "Name : AAA", .color = sf::Color(255, 255, 255, 255), .charSize = 80, .width = width/6.0f, .height = height/18.0f};
    setText(namePrint);
    setGames();
    setGraphic();
    for (std::size_t i = 0; i < this->_allGames.size(); i++)
        setLeaderboard(this->_allGames[i]);
    setSquare("graphic", sf::Color::White, 0);
    setSquare("games", sf::Color::White, 1);
    setSquare("leaderboard", sf::Color::White, 2);
    setSquare("game", sf::Color::White, 0);
    setSquare("lib", sf::Color::White, 0);
    setSquare("play", sf::Color::White, 0);
    setSprite("background", "assets/background.png");
}

void sfmlDisplay::sfml::setSpritePos(std::string name, object::Sprite_t sprite, Vector2i position, bool level)
{
    if (!level)
        return;
    if (this->_sprites.find(name) == this->_sprites.end())
        setSprite(name, sprite._filePath);
    int height = this->_window->getSize().y;
    sf::Vector2f pos(position.getX() * sprite._mult.getX() + sprite._extra.getX(), position.getY() * sprite._mult.getY() + sprite._extra.getY() + height * 0.2);
    sf::IntRect rect(sprite._rectSize.getX(), sprite._rectSize.getY(), sprite._sizeSquare.getX(), sprite._sizeSquare.getY());
    sf::Vector2f scale(sprite._scale.getX(), sprite._scale.getY());
    this->_sprites[name].setPosition(pos);
    this->_sprites[name].setTextureRect(rect);
    this->_sprites[name].setScale(scale);
    this->_window->draw(this->_sprites[name]);
}

void sfmlDisplay::sfml::display(arcade::IGameModule *game)
{
    this->_window->clear();
    std::vector<object::Object> obj = game->getObjects();
    std::string score = "SCORE : " + std::to_string(game->getSetting().getScore());
    if (this->_texts.find("scoreGame") == this->_texts.end()) {
        int width = this->_window->getSize().x;
        int height = this->_window->getSize().y;
        sfmlDisplay::text_t scoreGame = {.name = "scoreGame", .print = score, .color = sf::Color::White,
        .charSize = 100, .width = width/2.0f, .height = height/25.0f};
        setText(scoreGame);
    }
    this->_texts["scoreGame"].setString(score);
    this->_window->draw(this->_texts["scoreGame"]);
    for (int a = 0; a < 2; a++)
        for (std::size_t i = 0; i < obj.size(); i++) {
            std::string name = std::to_string(i) + std::to_string(obj[i].getContent());
            setSpritePos(name, obj[i].getSprite(), obj[i].getPos(), obj[i].getLevel() == a);
        }
    this->_window->display();
    this->_inputName = false;
    this->_play = false;
}

Vector2i sfmlDisplay::sfml::getEventClick()
{
    Vector2i res(-1, -1);
    if (this->_restartEvent == 4) {
        if (this->_window->pollEvent(this->_event))
            if (this->_event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i position = sf::Mouse::getPosition((*this->_window));
                res.setX(position.x);
                res.setY(position.y);
            }
    } else
        if (this->_event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i position = sf::Mouse::getPosition((*this->_window));
            res.setX(position.x);
            res.setY(position.y);
        }
    this->_restartEvent++;
    return res;
}

char sfmlDisplay::sfml::getKeyboardEvent()
{
    char res = 0;
    this->_time = this->_clock.getElapsedTime();
    if (this->_time.asMilliseconds() >= 100) {
        if (this->_restartEvent == 4) {
            if (this->_window->pollEvent(this->_event)) {
                if (this->_event.type == sf::Event::TextEntered)
                    res = this->_event.text.unicode;
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    res = '<';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    res = '>';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    res = '^';
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    res = 'V';
            }
        } else
            if (this->_event.type == sf::Event::TextEntered)
                res = this->_event.text.unicode;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                res = '<';
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                res = '>';
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                res = '^';
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                res = 'V';
        this->_restartEvent++;
        if (!this->_inputName)
            res = 0;
        if (res != 0) {
            this->_time = this->_clock.restart();
        }
    }
    return res;
}

std::unordered_map<std::string, std::string> *sfmlDisplay::sfml::displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs)
{
    std::unordered_map<std::string, std::string> *strings = new std::unordered_map<std::string, std::string>;
    int width = this->_window->getSize().x;
    int height = this->_window->getSize().y;
    this->_window->clear();
    this->_window->draw(this->_sprites["background"]);
    if (!this->_inputName) {
        this->_time = this->_clock.getElapsedTime();
        if (this->_time.asMilliseconds() >= 300) {
            char c = 0;
            if (this->_event.type == sf::Event::TextEntered)
                c = this->_event.text.unicode;
            if (c != 0) {
                if (c == 8) {
                    std::string name = this->_texts["name"].getString();
                    for (std::size_t i = 0; i < name.size(); i++)
                        if ((name[i] != '-' && i + 1 == name.size()) || (name[i] != '-' && name[i + 1] == '-')) {
                            name[i] = '-';
                            break;
                        }
                    this->_texts["name"].setString(name);
                    this->_time = this->_clock.restart();
                } else if ((c >= 'a' && c >= 'z') || (c >= 'A' && c >= 'Z')) {
                    std::string name = this->_texts["name"].getString();
                    for (std::size_t i = 0; i < name.size(); i++)
                        if (name[i] == '-') {
                            name[i] = c;
                            break;
                        }
                    this->_texts["name"].setString(name);
                    this->_time = this->_clock.restart();
                } else if (c == 13) {
                    std::string name = this->_texts["name"].getString();
                    std::size_t i = 0;
                    for (; i < name.size(); i++)
                        if (name[i] == '-') {
                            name[i] = c;
                            break;
                        }
                    if (i == name.size())
                        this->_inputName = true;
                }
            }
        }
        this->_window->draw(this->_texts["player"]);
        this->_window->draw(this->_texts["name"]);
    } else {
        this->_time = this->_clock.getElapsedTime();
        if (this->_time.asMilliseconds() >= 800) {
            Vector2i pos(-1, -1);
            if (this->_event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i position = sf::Mouse::getPosition((*this->_window));
                pos.setX(position.x);
                pos.setY(position.y);
                this->_time = this->_clock.restart();
            }
            if (pos.getX() != -1 && pos.getY() != -1) {
                for (long unsigned int i = 0; i < games.size(); i++) {
                    if (this->_texts.find(games[i]) != this->_texts.end()) {
                        sf::FloatRect textRect = this->_texts[graphs[i]].getLocalBounds();
                        sf::Vector2f posGame;
                        posGame.x = width/2.0f;
                        posGame.y = height/6.66f + (((height/1.25f) / (games.size() + 1)) * (i + 1));
                        if (pos.getX() >= posGame.x - textRect.width/2.0f && pos.getX() <= posGame.x + textRect.width &&
                        pos.getY() >= posGame.y - textRect.height/2.0f && pos.getY() <= posGame.y + textRect.height)
                            this->_game = (this->_game == games[i]) ? "" : games[i];
                    }
                }
                for (long unsigned int i = 0; i < graphs.size(); i++) {
                    if (this->_texts.find(graphs[i]) != this->_texts.end()) {
                        sf::FloatRect textRect = this->_texts[graphs[i]].getLocalBounds();
                        sf::Vector2f posLib;
                        posLib.x = width/6.0f;
                        posLib.y = height/6.66f + (((height/1.25f) / (graphs.size() + 1)) * (i + 1));
                        if (pos.getX() >= posLib.x - textRect.width/2.0f && pos.getX() <= posLib.x + textRect.width &&
                        pos.getY() >= posLib.y - textRect.height/2.0f && pos.getY() <= posLib.y + textRect.height)
                            this->_lib = (this->_lib == graphs[i]) ? "" : graphs[i];
                    }
                }
                sf::Vector2f posPlay = this->_texts["play"].getPosition();
                sf::FloatRect textRectPlay = this->_texts["play"].getLocalBounds();
                if (this->_print && pos.getX() >= posPlay.x - textRectPlay.width * 0.15f && pos.getX() <=  posPlay.x + textRectPlay.width && pos.getY() >= posPlay.y - textRectPlay.height * 0.06f && pos.getY() <=  posPlay.y + textRectPlay.width) {
                    this->_play = true;
                }
            }
        }
        if (this->_print)
            this->_texts["play"].setFillColor(sf::Color(255, 255, 255, 255));
        if (!this->_print)
            this->_texts["play"].setFillColor(sf::Color(255, 255, 255, 100));
        Vector2i posMouse(-1, -1);
        sf::Vector2i position = sf::Mouse::getPosition((*this->_window));
        posMouse.setX(position.x);
        posMouse.setY(position.y);
        this->_window->draw(this->_squares["graphic"]);
        this->_window->draw(this->_squares["games"]);
        this->_window->draw(this->_squares["leaderboard"]);
        this->_window->draw(this->_texts["arcade_menu"]);
        this->_window->draw(this->_texts["leaderboard"]);
        this->_window->draw(this->_texts["games"]);
        this->_window->draw(this->_texts["graphics"]);
        this->_window->draw(this->_texts["play"]);
        sf::Vector2f posPlay = this->_texts["play"].getPosition();
        sf::FloatRect textRectPlay = this->_texts["play"].getLocalBounds();
        if (this->_print &&
        posMouse.getX() >= posPlay.x - textRectPlay.width * 0.15f && posMouse.getX() <=  posPlay.x + textRectPlay.width && posMouse.getY() >= posPlay.y - textRectPlay.height * 0.06f && posMouse.getY() <=  posPlay.y + textRectPlay.width) {
            this->_squares["play"].setPosition(sf::Vector2f(posPlay.x - textRectPlay.width * 0.15f, posPlay.y - textRectPlay.height * 0.06f));
            this->_squares["play"].setSize(sf::Vector2f(textRectPlay.width * 1.3f, textRectPlay.height * 1.8f));
            this->_window->draw(this->_squares["play"]);
        }
        this->_texts["namePrint"].setString("Name : " + this->_texts["name"].getString());
        this->_time2 = this->_clock2.getElapsedTime();
        if (this->_time2.asSeconds() < 2)
            this->_texts["namePrint"].setFillColor(sf::Color::Blue);
        if (this->_time2.asSeconds() >= 2 && this->_time2.asSeconds() < 4)
            this->_texts["namePrint"].setFillColor(sf::Color::White);
        if (this->_time2.asSeconds() >= 4 && this->_time2.asSeconds() < 6)
            this->_texts["namePrint"].setFillColor(sf::Color::Red);
        if (this->_time2.asSeconds() >= 6)
            this->_time2 = this->_clock2.restart();
        this->_window->draw(this->_texts["namePrint"]);
        for (long unsigned int i = 0; i < games.size(); i++) {
            if (this->_texts.find(games[i]) != this->_texts.end()) {
                sf::FloatRect textRect = this->_texts[games[i]].getLocalBounds();
                sf::Vector2f pos;
                pos.x = width/2.0f;
                pos.y = height/6.66f + (((height/1.25f) / (games.size() + 1)) * (i + 1));
                this->_texts[games[i]].setPosition(sf::Vector2f(pos.x - textRect.width/2.0f, pos.y - textRect.height/2.0f));
                if (games[i] == this->_game) {
                    this->_squares["lib"].setPosition(sf::Vector2f(pos.x - textRect.width * 0.75f, pos.y - textRect.height * 0.65f));
                    this->_squares["lib"].setSize(sf::Vector2f(textRect.width * 1.5f, textRect.height * 2.25f));
                    this->_window->draw(this->_squares["lib"]);
                    const sf::Color colorTexte = this->_texts[games[i]].getFillColor();
                    sf::Color test = colorTexte;
                    test.a = 255;
                    this->_texts[games[i]].setFillColor(test);
                } else {
                    const sf::Color colorTexte = this->_texts[games[i]].getFillColor();
                    sf::Color test = colorTexte;
                    test.a = 100;
                    this->_texts[games[i]].setFillColor(test);
                }
                if (posMouse.getX() >= pos.x - textRect.width/2.0f && posMouse.getX() <= pos.x + textRect.width && posMouse.getY() >= pos.y - textRect.height/2.0f && posMouse.getY() <= pos.y + textRect.height) {
                    this->_squares["lib"].setPosition(sf::Vector2f(pos.x - textRect.width * 0.75f, pos.y - textRect.height * 0.65f));
                    this->_squares["lib"].setSize(sf::Vector2f(textRect.width * 1.5f, textRect.height * 2.25f));
                    this->_window->draw(this->_squares["lib"]);
                }
                this->_window->draw(this->_texts[games[i]]);
            }
        }
        for (long unsigned int i = 0; i < graphs.size(); i++) {
            if (this->_texts.find(graphs[i]) != this->_texts.end()) {
                sf::FloatRect textRect = this->_texts[graphs[i]].getLocalBounds();
                sf::Vector2f pos;
                pos.x = width/6.0f;
                pos.y = height/6.66f + (((height/1.25f) / (graphs.size() + 1)) * (i + 1));
                this->_texts[graphs[i]].setPosition(sf::Vector2f(pos.x - textRect.width/2.0f, pos.y - textRect.height/2.0f));
                if (graphs[i] == this->_lib) {
                    this->_squares["game"].setPosition(sf::Vector2f(pos.x - textRect.width * 0.75f, pos.y - textRect.height * 0.65f));
                    this->_squares["game"].setSize(sf::Vector2f(textRect.width * 1.5f, textRect.height * 2.25f));
                    this->_window->draw(this->_squares["game"]);
                    const sf::Color colorTexte = this->_texts[graphs[i]].getFillColor();
                    sf::Color test = colorTexte;
                    test.a = 255;
                    this->_texts[graphs[i]].setFillColor(test);
                } else {
                    const sf::Color colorTexte = this->_texts[graphs[i]].getFillColor();
                    sf::Color test = colorTexte;
                    test.a = 100;
                    this->_texts[graphs[i]].setFillColor(test);
                }
                if (posMouse.getX() >= pos.x - textRect.width/2.0f && posMouse.getX() <= pos.x + textRect.width && posMouse.getY() >= pos.y - textRect.height/2.0f && posMouse.getY() <= pos.y + textRect.height) {
                    this->_squares["game"].setPosition(sf::Vector2f(pos.x - textRect.width * 0.75f, pos.y - textRect.height * 0.65f));
                    this->_squares["game"].setSize(sf::Vector2f(textRect.width * 1.5f, textRect.height * 2.25f));
                    this->_window->draw(this->_squares["game"]);
                }
                this->_window->draw(this->_texts[graphs[i]]);
            }
        }
        for (std::size_t i = 0; i < this->_leader[this->_game].size(); i++)
            this->_window->draw(this->_texts[this->_game + "-" + std::to_string(i)]);
    }
    this->_window->display();
    (*strings)["play"] = (this->_play) ? "true" : "false";
    std::string name = this->_texts["name"].getString();
    for (std::size_t i = 0; i < name.size(); i++)
        if (name[i] == '-')
            return strings;
    (*strings)["name"] = name;
    (*strings)["game"] = this->_game;
    (*strings)["graph"] = this->_lib;
    (*strings)["play"] = (this->_play) ? "true" : "false";
    if (this->_game  != "" && this->_lib != "" && this->_print == false)
        this->_print = true;
    else if (this->_game  == "" || this->_lib == "")
        this->_print = false;
    return strings;
}

void sfmlDisplay::sfml::close()
{
    this->_window->close();
}

bool sfmlDisplay::sfml::forceExitPoint()
{
    if (this->_window->pollEvent(this->_event))
        if (this->_event.type == sf::Event::Closed)
            return true;
    this->_restartEvent++;
    return false;
}

extern "C" {
    sfmlDisplay::sfml sfmlLib;
    int entryPoint()
    {
        try {
            sfmlLib.open();
        } catch (error &e) {
            throw error(std::cerr, e.what());
        }
        std::cout << "Called init" << std::endl;
        return 0;
    }
    
    IDisplayModule *initDisplay()
    {
        IDisplayModule *SFML = new sfmlDisplay::sfml();
        return SFML;
    }

    Vector2i getEventClick(void)
    {
        try {
            return sfmlLib.getEventClick();
        } catch (error &e) {
            throw error(std::cerr, e.what());
        }
    }

    char getKeyboardEvent(void)
    {
        try {
            return sfmlLib.getKeyboardEvent();
        } catch (error &e) {
            throw error(std::cerr, e.what());
        }
        return 'n';
    }

    std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs)
    {
        try {
            return sfmlLib.displayMainMenu(games, graphs);
        } catch (error &e) {
            throw error(std::cerr, e.what());
        }
    }

    void exitPoint(void)
    {
        sfmlLib.close();
    }

    bool forceExitPoint(void)
    {
        return sfmlLib.forceExitPoint();
    }
}