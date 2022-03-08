/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <iostream>

namespace GUI {
    class Sound {
        public:
            Sound(std::string path);
            ~Sound();

            void playSong();
            void stopSong();

        protected:
        private:
            std::string _path;
    };
}

#endif /* !SOUND_HPP_ */
