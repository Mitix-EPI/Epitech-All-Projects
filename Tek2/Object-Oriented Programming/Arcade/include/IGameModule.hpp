/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <chrono>
#include <ctime>
#include "UtilityClasses.hpp"

namespace arcade {
    class IGameModule {
        public:
            virtual ~IGameModule() = default;
            virtual bool update(Vector2i mouse, char key) = 0;
            virtual void handleMouseEvent() = 0;
            virtual void handleKeyEvent(char key) = 0;
            virtual std::vector<object::Object> getObjects() = 0;
            virtual Settings getSetting() = 0;
            virtual void reset(void) = 0;

        protected:
        private:
    };
}

#endif /* !IGAMEMODULE_HPP_ */
