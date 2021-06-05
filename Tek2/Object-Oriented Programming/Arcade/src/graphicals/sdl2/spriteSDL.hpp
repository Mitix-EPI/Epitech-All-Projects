/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** spriteSDL
*/

#ifndef SPRITESDL_HPP_
#define SPRITESDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include <iostream>
#include "UtilityClasses.hpp"

class spriteSDL {
    public:
        SDL_Texture *_texture;
        SDL_Surface *_surface;
        SDL_Rect _imageRect;
        SDL_Rect _pos;
        spriteSDL() {}
        ~spriteSDL();
        spriteSDL(object::Object object, SDL_Renderer *renderer);
        void setPos(Vector2i);
        void displaySprite(SDL_Renderer *renderer);
        void updateSprite(object::Object object);
        std::string filepath;
};


#endif /* !SPRITESDL_HPP_ */
