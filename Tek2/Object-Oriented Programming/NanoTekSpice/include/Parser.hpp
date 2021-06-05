/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "IComponent.hpp"
#include "Misc.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <iterator>
#include <unordered_map>
#include <algorithm>

class Parser {
    public:
        Parser(std::string filepath);
        ~Parser();

        static std::string parseLine(std::string line);

        // GETTERS

        std::vector<std::string> getClearContent(void) const { return (this->_clearContent); }
        std::map<std::string, std::string> getChipsets(void) const { return (this->_chipsets); }
        std::map<std::string, nts::Tristate> getChipsetsValues(void) const { return (this->_chipsetsValues); }
        std::vector<std::vector<std::string>> getLinks(void) const { return (this->_links); }

    protected:
        void _parseContent(void);
        void _checkContent(void);

        void _registerLine(std::string line, std::string type);

        std::string _setChipsetValue(std::vector<std::string> words);
        bool _linkExists(std::vector<std::string> link1, std::vector<std::string> link2);

    private:
        std::string _filepath;
        std::vector<std::string> _clearContent;
        std::map<std::string, std::string> _chipsets; // Name -> Component Type
        std::map<std::string, nts::Tristate> _chipsetsValues; // Name -> value (TRUE, FALSE, UNDEFINED)
        std::vector<std::vector<std::string>> _links; // Name, link, name2, link2

        const std::vector<std::string> _componentsName = {"input", "output", "true", "clock",
            "logger", "false", "4801", "4514", "4512", "4094", "4081", "4071", "4069", "4040",
            "4030", "4017", "4013", "4011", "4008", "4001", "2716"};
        const std::vector<std::string> _allowedComponentsValues = {"input", "clock"};
};

#endif /* !PARSER_HPP_ */
