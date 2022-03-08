/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** WindowTemplates
*/

#include "WindowTemplates.hpp"
#include "WindowManager.hpp"

GUI::WindowTemplates::WindowTemplates(WindowManager *parent)
   : QWidget(&parent->_win)
   , _parent(parent)
{
    setFixedSize(WIDTH, HEIGHT);

}

GUI::WindowTemplates::~WindowTemplates()
{
}