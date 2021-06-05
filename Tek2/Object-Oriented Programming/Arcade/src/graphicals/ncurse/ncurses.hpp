/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <vector>
#include <string>
#include <unordered_map>
#include <assert.h>
#include <ncurses.h>
#include <unistd.h>
#include <map>
#include <tuple>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "UtilityClasses.hpp"
#include "ascii_alphabet.hpp"

static std::vector<std::string> arcadeNameMenu =
{
    "  __   ____   ___   __   ____  ____ ",
    " / _\\ (  _ \\ / __) / _\\ (    \\(  __)",
    "/    \\ )   /( (__ /    \\ ) D ( ) _) ",
    "\\_/\\_/(__\\_) \\___)\\_/\\_/(____/(____)",
};

static std::vector<std::string> arcadePlayMenu =
{
    " ____  __     __   _  _ ",
    "(  _ \\(  )   / _\\ ( \\/ )",
    " ) __// (_/\\/    \\ )  / ",
    "(__)  \\____/\\_/\\_/(__/  ",
};

const std::vector<std::string> _gameLibNames =
{
    "nibbler", "pacman", "qix",
    "centipede", "solarfox"
};

class ncurses : public IDisplayModule
{
    public:
        ncurses();
        ~ncurses();

    public:
        void open(void);
        void close(void);
        void display(arcade::IGameModule *);
        Vector2i getEventClick(void);
        char getKeyboardEvent(void);
        std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs);
        void menu(std::vector<std::string> games, std::vector<std::string> graphs);
        void writeName(void);
        bool forceExitPoint(void);
        bool handleClick(std::vector<std::string> games, std::vector<std::string> graphs);
        void initLeaderboard(void);
        void displayLayout(std::size_t size, arcade::IGameModule *game);
        void objectColorOn(Vector3i color);
        void objectColorOff(Vector3i color);
        void refresh(void);
        void playMenuMusic(void);
        void changeGame(void);

    public:
        std::size_t scene = 0;
        std::string name;
        Vector2i clickedPos;
        int idxGame = 0;
        int idxGraph = 0;
        int ch = 0;
        bool playGame = false;
        bool firstTime = true;
        std::map<std::string, std::vector<std::tuple<std::string, int>>> _leader;
        WINDOW *game;
        bool firstDisplay = true;

};

#endif /* !NCURSES_HPP_ */
