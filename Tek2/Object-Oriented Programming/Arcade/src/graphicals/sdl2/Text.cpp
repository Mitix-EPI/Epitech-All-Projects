/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(const char *text, const char *filepath, SDL_Renderer *renderer, SDL_Color color, int fonSize)
{
    _font = TTF_OpenFont(filepath, fonSize);
    _color = color;
    _text = text;
    if (!_font) {
        std::cerr << "Font cannot be loaded" << std::endl;
        exit(84);
    }
    _surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
    if (!_surface) {
        std::cerr << "Surface cannot be set" << std::endl;
        exit(84);
    }
    _texture = SDL_CreateTextureFromSurface(renderer, _surface);
    if (!_texture) {
        std::cerr << "Texture cannot be rendered" << std::endl;
        exit(84);
    }
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(_texture, NULL, NULL, &texW, &texH);
    _Message_rect.x = 0;  
    _Message_rect.y = 0;
    _Message_rect.w = texW;
    _Message_rect.h = texH;
}

Text::Text(Text *text)
{
    this->_color = text->_color;
    this->_font = text->_font;
    this->_Message_rect = text->_Message_rect;
    this->_surface = text->_surface;
    this->_text = text->_text;
    this->_texture = text->_texture;
}

void Text::displayText(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, _texture, NULL, &_Message_rect);
}

void Text::setColor(Uint8 r, Uint8 g, Uint8 b, SDL_Renderer *renderer) 
{
    SDL_Color color = {r, g, b};
    _color = color;
    _surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
    if (!_surface) {
        std::cerr << "Surface cannot be set" << std::endl;
        exit(84);
    }
    _texture = SDL_CreateTextureFromSurface(renderer, _surface);
    if (!_texture) {
        std::cerr << "Texture cannot be rendered" << std::endl;
        exit(84);
    }
}

void Text::setText(const char *text, SDL_Renderer *renderer)
{
    _text = text;
    _surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
    if (!_surface) {
        std::cerr << "Surface cannot be set" << std::endl;
        exit(84);
    }
    _texture = SDL_CreateTextureFromSurface(renderer, _surface);
    if (!_texture) {
        std::cerr << "Texture cannot be rendered" << std::endl;
        exit(84);
    }
}

void Text::setPos(int x, int y)
{
    _Message_rect.x = x;
    _Message_rect.y = y;
}

void Text::setSize(int width, int height)
{
    _Message_rect.w = width;
    _Message_rect.h = width;
}

void Text::setSelected(bool selected, SDL_Renderer *renderer)
{
    _selected = selected;
    if (_selected) {
        setColor(50, 205, 50, renderer);
    } else {
        setColor(255, 255, 255, renderer);
    }
}

bool Text::isCLickInRect(Vector2i clicked)
{
    int x = clicked.getX();
    int y = clicked.getY();
    if (x > _Message_rect.x && x < (_Message_rect.x + _Message_rect.w) && y > _Message_rect.y && y < (_Message_rect.y + _Message_rect.h)) {
        return (true);
    }
    return false;
}

Text::~Text()
{
    SDL_DestroyTexture(_texture);
    SDL_FreeSurface(_surface);
    TTF_CloseFont(_font);
}