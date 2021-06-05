/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** sfml
*/

#ifndef LEADERBOARD_HPP_
#define LEADERBOARD_HPP_

#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
#include <tuple>
#include <iostream>

std::vector<std::tuple<std::string, int>> getTopPlayers(std::string name);

#endif