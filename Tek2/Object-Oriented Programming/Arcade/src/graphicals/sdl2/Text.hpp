/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Text
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include "UtilityClasses.hpp"

#ifndef TEXT_HPP_
#define TEXT_HPP_

class Text {
    public:
    
        SDL_Texture *_texture;
        SDL_Surface *_surface;
        TTF_Font *_font;
        SDL_Color _color;
        SDL_Rect _Message_rect;
        std::string _text;
        bool _selected = false;

        Text(const char *text, const char *filepath, SDL_Renderer *renderer, SDL_Color color, int fontSize = 35);
        Text(Text *text);
        void setText(const char *text, SDL_Renderer *renderer);
        void setPos(int x, int y);
        void setSize(int width, int height);
        void setColor(Uint8 r, Uint8 g, Uint8 b, SDL_Renderer *renderer);
        void displayText(SDL_Renderer *renderer);
        void setSelected(bool, SDL_Renderer*);
        bool isCLickInRect(Vector2i clicked);
        ~Text();

    protected:
    private:
        
};

#endif /* !TEXT_HPP_ */
