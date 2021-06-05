/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Exceptions.hpp"

Parser::Parser(std::string filepath)
{
    this->_filepath = filepath;
    this->_parseContent();
}

std::string Parser::parseLine(std::string line)
{
    std::string comment = "#";
    std::string clearLine;
    size_t pos = 0;
    bool firstChar = false;

    pos = line.find(comment);
    if (pos != std::string::npos) {
        clearLine = line.substr(0, pos);
    } else {
        clearLine = line;
    }
    for (std::string::iterator i = clearLine.begin(); i != clearLine.end();) {
        std::string::iterator k = i;
        k++;
        if (!isspace(*i) && !firstChar) {
            firstChar = true;
            i++;
        }
        if (isspace(*i) && !firstChar) {
            i = clearLine.erase(i);
        } else if (isspace(*i) && isspace(*k)) {
            i = clearLine.erase(i);
        } else if (isspace(*i) && k == clearLine.end()) {
            i = clearLine.erase(i);
        } else {
            i++;
        }
    }
    return (clearLine);
}

bool Parser::_linkExists(std::vector<std::string> link1, std::vector<std::string> link2)
{
    for (const auto &it : this->_links) {
        if (link1[0] == it.at(0)) {
            if (link1[1] == it.at(1)) {
                return (true);
            }
        } else if (link1[0] == it.at(2)) {
            if (link1[1] == it.at(3)) {
                return (true);
            }
        } else if (link2[0] == it.at(0)) {
            if (link2[1] == it.at(1)) {
                return (true);
            }
        } else if (link2[0] == it.at(2)) {
            if (link2[1] == it.at(3)) {
                return (true);
            }
        }
    }
    return (false);
}

std::string Parser::_setChipsetValue(std::vector<std::string> words)
{
    if (words[1].find('(') != std::string::npos) {
        std::string nStr;
        std::string value;

        if (std::find(this->_allowedComponentsValues.begin(), this->_allowedComponentsValues.end(), words[0]) == this->_allowedComponentsValues.end()) {
            throw InvalidComponent("Component cannot have his value set", 16);
        }
        if (words[1].find(')') == std::string::npos) {
            throw InvalidComponent("Missing bracket ')' on component", 17);
        }
        value = words[1].substr(words[1].find('(')+1, words[1].find(')') - words[1].find('(') - 1);
        int val = -10;

        try {
            val = std::stoi(value);
        } catch (std::exception const &e) {
            throw InvalidComponent("Unknown set value for component.", 18);
        }
        if (val != nts::Tristate::UNDEFINED && val != nts::Tristate::TRUE &&
            val != nts::Tristate::FALSE) {
                throw InvalidComponent("Unknown set value for component.", 18);
            }

        nStr = words[1].substr(0, words[1].find('('));
        if (val == 0) {
            this->_chipsetsValues.insert(std::make_pair(nStr, nts::Tristate::FALSE));
        } else if (val == 1) {
            this->_chipsetsValues.insert(std::make_pair(nStr, nts::Tristate::TRUE));
        } else {
            this->_chipsetsValues.insert(std::make_pair(nStr, nts::Tristate::UNDEFINED));
        }
        return (nStr);
    } else {
        if (words[1].find(')') != std::string::npos) {
            throw InvalidComponent("Missing bracket '(' on component", 17);
        }
        this->_chipsetsValues.insert(std::make_pair(words[1], nts::Tristate::UNDEFINED));
        return (words[1]);
    }
}

void Parser::_registerLine(std::string line, std::string type)
{
    std::vector<std::string> words;

    if (type.empty()) {
        throw UndefinedContentType("Unknown type in file. Is it a chipset or a link ?", 4);
    }
    if (line.empty()) {
        throw EmptyContent("Line is empty.", 7);
    }
    words = misc::split(line, ' ');
    if (type == "chipsets") {
        if (words.size() != 2) {
            throw InvalidChipset("Invalid chipset line. Expected: '<Component> <Name>'", 9);
        }
        if (std::find(this->_componentsName.begin(), this->_componentsName.end(), words[0]) == this->_componentsName.end()) {
            throw InvalidComponent("Component do not exists.", 10);
        }
        if (this->_chipsets.find(words[1]) != this->_chipsets.end()) {
            throw InvalidName("Component name is already used.", 11);
        }
        words[1] = this->_setChipsetValue(words);
        this->_chipsets[words[1]] = words[0];

    } else if (type == "links") {
        if (words.size() != 2) {
            throw InvalidLink("Invalid link line. Expected: '<ComponentName:pin> <ComponentName2:pin2>'", 12);
        }
        std::vector<std::string> link1 = misc::split(words[0], ':');
        std::vector<std::string> link2 = misc::split(words[1], ':');
        if (link1.size() != 2 || link2.size() != 2) {
            throw InvalidLink("Invalid link line. Expected: '<ComponentName:pin> <ComponentName2:pin2>'", 12);
        }
        if (!misc::isNumber(link1[1]) || !misc::isNumber(link2[1])) {
            throw InvalidPin("Component pin is not a number.", 13);
        }
        if (this->_chipsets.find(link1[0]) == this->_chipsets.end() || this->_chipsets.find(link2[0]) == this->_chipsets.end()) {
            throw InvalidName("Invalid link component name.", 14);
        }
        if (this->_linkExists(link1, link2)) {
            throw InvalidLink("Component pin already linked.", 15);
        }
        this->_links.push_back({link1[0], link1[1], link2[0], link2[1]});
    } else {
        throw UndefinedContentType("Bad type in file.", 8);
    }
}

void Parser::_checkContent(void)
{
    std::string type = "";
    std::string line = "";

    if (this->_clearContent.empty())
        throw EmptyContent("File content is empty.", 3);

    for (size_t i = 0; i < this->_clearContent.size(); i += 1) {
        line = this->_clearContent[i];
        if (line == ".chipsets:") {
            type = "chipsets";
            continue;
        }
        if (line == ".links:") {
            type = "links";
            continue;
        }
        this->_registerLine(line, type);
    }
}

void Parser::_parseContent(void)
{
    std::string line;
    std::string extension;
    std::size_t pos;

    try {
        if (this->_filepath.empty()) {
            throw InvalidFilepath("Filepath is empty.", 1);
        }
        pos = this->_filepath.find(".");
        if (pos == std::string::npos) {
            throw UnknownFileExtension("File extension not found.", 5);
        }
        pos = this->_filepath.find(".nts");
        if (pos + 4 != this->_filepath.length()) {
            throw UnknownFileExtension("Bad file extension.", 6, this->_filepath);
        }
        std::ifstream file(this->_filepath);
        if (!file.is_open()) {
            throw InvalidFilepath("Can't open this file.", 2, this->_filepath);
        }
        while (std::getline(file, line)) {
            line = this->parseLine(line);
            if (!line.empty())
                this->_clearContent.push_back(line);
        }
        this->_checkContent();

    } catch (InvalidFilepath const &e) {
        readException(e);
        exit(84);
    } catch (EmptyContent const &e) {
        readException(e);
        exit(84);
    } catch (UnknownFileExtension const &e) {
        readException(e);
        exit(84);
    } catch (UndefinedContentType const &e) {
        readException(e);
        exit(84);
    } catch (InvalidComponent const &e) {
        readException(e);
        exit(84);
    } catch (InvalidChipset const &e) {
        readException(e);
        exit(84);
    } catch (InvalidName const &e) {
        readException(e);
        exit(84);
    } catch (InvalidLink const &e) {
        readException(e);
        exit(84);
    } catch (InvalidPin const &e) {
        readException(e);
        exit(84);
    }
}

Parser::~Parser()
{
}
