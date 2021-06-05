/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Settings
*/

#include <map>
#include <iostream>

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

enum scenes
{
    GAME,
    PAUSE,
    GAMEOVER
};

class Settings {
    public:
        //Constructor
        Settings(std::string musicPath, std::string assestsPath);

        //Destructor
        ~Settings();

        //Getters
        std::size_t getScore() { return this->_score; }
        std::string getMusicFolderPath() { return this->_musicFolderPath; }
        std::string getAssetsFolderPath() { return this->_assestsFolderPath; }
        std::map<char, std::string> getKeys() { return this->_keys; }
        enum scenes getScene() { return this->_scene; }

        //Setters
        void setScore(std::size_t score) { this->_score = score; }
        void setMusicFolderPath(std::string musicFolderPath) { this->_musicFolderPath = musicFolderPath; }
        void setAssestFolderPath(std::string assetsFolderPath) { this->_assestsFolderPath = assetsFolderPath; }
        void setKeys(std::map<char, std::string> keyMap) { this->_keys = keyMap; }
        void setScene(enum scenes scene) { this->_scene = scene; }

    protected:

    private:
        std::size_t _score = 0;
        std::string _musicFolderPath = "";
        std::string _assestsFolderPath = "";
        std::map<char, std::string> _keys;
        enum scenes _scene = scenes::GAME;
};

#endif /* !SETTINGS_HPP_ */
