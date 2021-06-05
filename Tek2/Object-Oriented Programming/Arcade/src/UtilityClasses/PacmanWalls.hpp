/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** pacman walls
*/

#ifndef PACMANWALLS_HPP_
#define PACMANWALLS_HPP_

#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
#include <tuple>
#include <iostream>
#include "UtilityClasses.hpp"

Vector2i createWalls(std::unordered_map<std::string, char> square);

#endif