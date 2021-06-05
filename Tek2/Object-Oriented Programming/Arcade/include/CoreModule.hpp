/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** CoreModule
*/

#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

class Encapsulation;

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <dlfcn.h>
#include <fstream>
#include "Encapsulation.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

class CoreModule {
    public:
        CoreModule(char *filepath);
        ~CoreModule();

        void updateLibrairies(void);
        void launchArcade(void);
        void handlingChangingLib(char ch);
        void increaseGameIdx(void);
        void increaseGraphIdx(void);
        void decreaseGameIdx(void);
        void decreaseGraphIdx(void);
        bool isGraphLib(char *filename);
        bool isGameLib(char *filename);
        std::string parseFilename(std::string filename);
        void switchToMenu(void);
        void updateScore(void);

        std::string _userName;
        std::vector<void *> _handles;
        std::vector<std::string> _graphLibName; // 0 - ncurse
        std::vector<std::string> _gameLibName; // 0 - nibbler
        std::vector<IDisplayModule *> _graphLibrairies; // at(0) -> ncurse
        std::vector<arcade::IGameModule *> _gameLibrairies; // at(0) -> nibbler
        std::unordered_map<std::string, std::string> *_menu;
        std::size_t _idxGraph = 0;
        std::size_t _idxGame = 0;
        std::size_t _nbLibGraph = 0;
        std::size_t _nbLibGame = 0;

        Encapsulation *exec;

        const std::vector<std::string> _graphLibNames = {
            "arcade_ncurses.so", "arcade_sdl2.so", "arcade_sfml.so", "arcade_vulcan.so",
            "arcade_ndk++.so", "arcade_aa-lib.so", "arcade_libcaca.so", "arcade_allegro5.so",
            "arcade_xlib.so", "arcade_gtk+.so", "arcade_irrlicht.so", "arcade_qt5.so"
        };
        const std::vector<std::string> _gameLibNames = {
            "arcade_nibbler.so", "arcade_pacman.so", "arcade_qix.so",
            "arcade_centipede.so", "arcade_solarfox.so"
        };
};

int displayHelp(void);
void errorDisplay(int errorCode, std::string errorMessage);

#endif /* !COREMODULE_HPP_ */
