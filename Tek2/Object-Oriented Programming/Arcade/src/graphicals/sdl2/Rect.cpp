/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Rect
*/

#include "Rect.hpp"

Rect::Rect(int x, int y, int w, int h)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;
}

void Rect::displayRect(SDL_Renderer *renderer)
{
    if (this->_selected)
        SDL_SetRenderDrawColor(renderer, 50 ,205, 50, 255);
    else
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &this->_rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

bool Rect::isCLickInRect(Vector2i clicked)
{
    int x = clicked.getX();
    int y = clicked.getY();
    if (x > _rect.x && x < (_rect.x + _rect.h) && y > _rect.y && y < (_rect.y + _rect.w)) {
        return (true);
    }
    return false;
}