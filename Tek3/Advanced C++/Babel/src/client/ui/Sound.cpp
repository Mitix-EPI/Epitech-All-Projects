/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Sound
*/

#include "Sound.hpp"

GUI::Sound::Sound(std::string path)
{
    _path = path;
}

GUI::Sound::~Sound()
{
}

void GUI::Sound::playSong()
{
    std::system("paplay src/client/ui/call_sound.wav & > /dev/null 2>&1");
}

void GUI::Sound::stopSong()
{
    std::system("killall paplay");
}