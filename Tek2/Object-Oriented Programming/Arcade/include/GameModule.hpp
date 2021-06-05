/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** GameModule
*/

#ifndef GAMEMODULE_HPP_
#define GAMEMODULE_HPP_

#include <vector>
#include "IGameModule.hpp"
#include "UtilityClasses.hpp"

namespace games {
    class GameModule: public arcade::IGameModule {
        public:
            GameModule();
            ~GameModule();
            void setObjects(std::vector<object::Object> obj) { this->_objects = obj; };
            void setTiles(std::vector<object::Object> tiles) { this->_tiles = tiles; };
            void setSetting(Settings setting) { this->_settings = setting; };
            std::vector<object::Object> getObjects() { return this->_objects; };
            std::vector<object::Object> getTiles() { return this->_tiles; };
            Settings getSetting() { return this->_settings; };
            void reset(void);

        protected:
            std::vector<object::Object> _objects;
            std::vector<object::Object> _tiles;
            Settings _settings;
        private:
    };
}

#endif /* !GAMEMODULE_HPP_ */
