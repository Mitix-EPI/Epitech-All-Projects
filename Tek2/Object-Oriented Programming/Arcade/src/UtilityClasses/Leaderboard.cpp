/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** leaderboard
*/

#include "Leaderboard.hpp"

std::vector<std::tuple<std::string, int>> getTopPlayers(std::string name)
{
    std::regex word_regex("^[\t ]*(\\w+),[\t ]*(\\d+)$");
    std::string content;
    std::ifstream file;
    std::vector<std::tuple<std::string, int>> topPLayers;
    std::smatch pieces_match;
    std::vector<std::string> tokens;
    file.open("assets/" + name + "/leaderboard.txt");
    if (!file) {
        std::cerr << "File is not open" << std::endl;
        return topPLayers;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty" << std::endl;
        return topPLayers;
    }
    for (int lineNbr = 1; std::getline(file, content); lineNbr++) {
        if (std::regex_match(content, pieces_match, word_regex)) {
            for (size_t i = 0; i < pieces_match.size(); ++i)
                tokens.push_back(pieces_match[i].str());
            if (topPLayers.empty()) {
                topPLayers.push_back(std::make_tuple(tokens[1], std::stoi(tokens[2])));
            } else {
                long unsigned int size = topPLayers.size();
                for (long unsigned int i = 0; i < topPLayers.size(); i++) {
                    if (std::get<1>(topPLayers[i]) < std::stoi(tokens[2])) {
                        topPLayers.insert(topPLayers.begin() + i, std::make_tuple(tokens[1], std::stoi(tokens[2])));
                        break;
                    }
                }
                if (size == topPLayers.size())
                    topPLayers.push_back(std::make_tuple(tokens[1], std::stoi(tokens[2])));
            }
            tokens.clear();
        }
    }
    return topPLayers;
}