/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
#include <tuple>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"
#include "UtilityClasses.hpp"
#include "Errors/error.hpp"


namespace sfmlDisplay {

    typedef struct text_s {
        std::string name;
        std::string print;
        sf::Color color;
        int charSize;
        float width;
        float height;
    } text_t;

    class sfml: public IDisplayModule
    {
        public:
            sfml();
            ~sfml();

            // Global functions
            void open(void);
            void display(arcade::IGameModule *game);
            Vector2i getEventClick(void);
            char getKeyboardEvent(void);
            std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs);
            void close(void);
            bool forceExitPoint(void);

            // Functions specific
            void setGames();
            void setGraphic();
            void destroyEverything();
            void setText(text_t text, bool is_bold = false);
            void setSquare(std::string name, sf::Color color, int squareType);
            void setSprite(std::string name, std::string path);
            void setLeaderboard(std::string name);
            void setSpritePos(std::string name, object::Sprite_t sprite, Vector2i position, bool level);
            void changeGame(void);
        protected:
        private:
            sf::Font _menuText;
            sf::Texture _testText;
            sf::RenderWindow *_window;
            sf::Event _event;
            sf::Cursor _cursor;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::Text> _texts;
            std::map<std::string, sf::Text> _textsName;
            std::map<std::string, sf::Sprite> _sprites;
            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::RectangleShape> _squares;
            std::vector<std::string> _allGames;
            std::vector<std::string> _allGraphics;
            std::map<std::string, std::vector<std::tuple<std::string, int>>> _leader;
            bool _inputName;
            std::string _playerName;
            int _restartEvent;
            sf::Clock _clock;
            sf::Time _time;
            sf::Clock _clock2;
            sf::Time _time2;
            std::string _game;
            std::string _lib;
            bool _print;
            bool _play;
    };
};

#endif /* !SFML_HPP_ */
