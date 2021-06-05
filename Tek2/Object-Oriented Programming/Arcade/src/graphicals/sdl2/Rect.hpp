/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Rect
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include "UtilityClasses.hpp"

#ifndef Rect_HPP_
#define Rect_HPP_

class Rect {
    public:
    
        SDL_Rect _rect;
        bool _selected = false;

        Rect(int x, int y, int w, int h);
        void displayRect(SDL_Renderer *renderer);
        bool isCLickInRect(Vector2i clicked);
        ~Rect();

    protected:
    private:
        
};

#endif /* !Rect_HPP_ */
