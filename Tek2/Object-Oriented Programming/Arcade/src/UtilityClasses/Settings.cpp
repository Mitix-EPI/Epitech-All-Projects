/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Settings
*/

#include "Settings.hpp"


//-------------------------------- Constructors ---------------------------------------//

Settings::Settings(std::string musicPath, std::string assestsPath)
{
    this->_musicFolderPath = musicPath;
    this->_assestsFolderPath = assestsPath;
}


//-------------------------------- Destructor -----------------------------------------//

Settings::~Settings()
{
}

//-------------------------------- END ------------------------------------------------//
