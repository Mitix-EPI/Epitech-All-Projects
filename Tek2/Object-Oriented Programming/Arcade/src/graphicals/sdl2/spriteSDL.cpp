/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** spriteSDL
*/

#include "spriteSDL.hpp"

spriteSDL::spriteSDL(object::Object object, SDL_Renderer *renderer)
{
    filepath = object.getSprite()._filePath;
    _surface = IMG_Load(filepath.c_str());
    if (_surface == NULL) {
        exit(84);
    }
    _imageRect.x = object.getSprite()._rectSize.getX();
    _imageRect.y = object.getSprite()._rectSize.getY();
    _imageRect.w = object.getSprite()._sizeSquare.getX();
    _imageRect.h = object.getSprite()._sizeSquare.getY();


    _pos.x = object.getPos().getX() * object.getSprite()._mult.getX();
    _pos.y = object.getPos().getY() * object.getSprite()._mult.getY();
    _pos.w = object.getSprite()._sizeSquare.getX() * object.getSprite()._scale.getX();
    _pos.h = object.getSprite()._sizeSquare.getY() * object.getSprite()._scale.getY();
    
    _texture = SDL_CreateTextureFromSurface(renderer, _surface);
}

void spriteSDL::updateSprite(object::Object object)
{
    _imageRect.x = object.getSprite()._rectSize.getX();
    _imageRect.y = object.getSprite()._rectSize.getY();
    _imageRect.w = object.getSprite()._sizeSquare.getX();
    _imageRect.h = object.getSprite()._sizeSquare.getY();

    _pos.x = object.getPos().getX() * object.getSprite()._mult.getX() + object.getSprite()._extra.getX();
    _pos.y = object.getPos().getY() * object.getSprite()._mult.getY() + object.getSprite()._extra.getY();
    _pos.w = object.getSprite()._sizeSquare.getX() * object.getSprite()._scale.getX();
    _pos.h = object.getSprite()._sizeSquare.getY() * object.getSprite()._scale.getY();
}

void spriteSDL::displaySprite(SDL_Renderer *renderer)
{
    int error = SDL_RenderCopy(renderer, _texture, &_imageRect, &_pos);
}

void spriteSDL::setPos(Vector2i newPos)
{
    this->_pos.x = newPos.getX();
    this->_pos.y = newPos.getY();
}


spriteSDL::~spriteSDL()
{
    // SDL_DestroyTexture(_texture);
    // SDL_FreeSurface(_surface);
}