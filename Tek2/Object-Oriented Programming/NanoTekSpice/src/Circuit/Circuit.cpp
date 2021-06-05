/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(Parser parser)
{
    this->_tick = 0;
    this->_fill(parser);
    this->_setLinks(parser);
    this->_setValues(parser);
}

void Circuit::_fill(Parser parser)
{
    try {
        this->_mapComponentsType = parser.getChipsets();

        for (const auto &it : this->_mapComponentsType) {
            auto component = createComponent(it.second);
            this->_mapComponents.insert(std::make_pair(it.first, std::move(component)));
            if (it.second == "input" || it.second == "clock") {
                C_InputTmp *tmp = new C_InputTmp();
                this->_tmpMapComponents.insert(std::make_pair(it.first, tmp));
                this->_tmpMapComponentsType.insert(std::make_pair(it.first, it.second));

                this->_mapComponents.at(it.first)->setLink(2, *tmp, 100);
                tmp->setLink(1, *this->_mapComponents.at(it.first).get(), 2);
                this->_arrayTmp.push_back(tmp);
            }
        }
    } catch (InvalidPin const &e) {
        readException(e);
        exit(84);
    } catch (VDDSet const &e) {
        readException(e);
        exit(84);
    } catch (VSSSet const &e) {
        readException(e);
        exit(84);
    }
}

void Circuit::_setValues(Parser parser)
{
    try {
        auto chipsetsValue = parser.getChipsetsValues();

        for (const auto &it : chipsetsValue) {
            if (it.second != nts::Tristate::UNDEFINED) {
                if (this->_mapComponentsType.at(it.first) == "input" || this->_mapComponentsType.at(it.first) == "clock") {
                    this->_tmpMapComponents.at(it.first)->setStatus(it.second);
                    this->_mapComponents.at(it.first)->simulate(1);
                }
            }
        }
    } catch (InvalidPin const &e) {
        readException(e);
        exit(84);
    }
}

void Circuit::_setLinks(Parser parser)
{
    try {
        std::vector<std::vector<std::string>> links = parser.getLinks();
        std::size_t pinLink1;
        std::string link2;
        std::size_t pinLink2;

        for (const auto &it : links) {
            pinLink1 = (std::size_t) stoi(it.at(1));
            link2 = it.at(2);
            pinLink2 = (std::size_t) stoi(it.at(3));
            this->_mapComponents.at(it.at(0))->setLink(pinLink1, *(this->_mapComponents.at(link2).get()), pinLink2);
            this->_mapComponents.at(link2)->setLink(pinLink2, *(this->_mapComponents.at(it.at(0)).get()), pinLink1);
        }
    } catch (InvalidPin const &e) {
        readException(e);
        exit(84);
    } catch (VDDSet const &e) {
        readException(e);
        exit(84);
    } catch (VSSSet const &e) {
        readException(e);
        exit(84);
    }
}

void Circuit::setValue(std::string varName, nts::Tristate status)
{
    if (this->_tmpMapComponents.find(varName) == this->_tmpMapComponents.end()) {
        throw InvalidName("Invalid variable name", 20, varName);
    } else {
        this->_tmpMapComponents.at(varName)->setStatus(status);
    }
}

std::string Circuit::displayCompute(nts::Tristate status)
{
    std::string display = "U";
    if (status == nts::Tristate::TRUE) {
        display = "1";
    } else if (status == nts::Tristate::FALSE) {
        display = "0";
    }
    return display;
}

void Circuit::display(void)
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto &it : this->_mapComponentsType) {
        if (it.second == "input" || it.second == "clock") {
            std::cout << "  " << it.first << ": ";
            std::cout << this->displayCompute(this->_mapComponents.at(it.first)->compute(1)) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (const auto &it : this->_mapComponentsType) {
        if (it.second == "output") {
            std::cout << "  " << it.first << ": ";
            std::cout << this->displayCompute(this->_mapComponents.at(it.first)->compute(1)) << std::endl;
        }
    }
}

void Circuit::reset(void)
{
    for (const auto &it : this->_mapComponentsType) {
        if (it.second == "4040" || it.second == "4013" || it.second == "4017") {
            this->_mapComponents.at(it.first)->simulate(84);
        }
    }
}

void Circuit::simulate(void)
{
    // RESET COMPUTE STATE
    this->reset();
    for (const auto &it : this->_mapComponentsType) {
        if (it.second == "output" || it.second == "logger") {
            this->_mapComponents.at(it.first)->simulate(1);
        }
    }
    this->invertClock();
    this->_tick++;
}

void Circuit::invertClock(void)
{
    for (const auto &it : this->_tmpMapComponentsType) {
        if (it.second == "clock") {
            this->_tmpMapComponents.at(it.first)->switchValue();
        }
    }
}

void Circuit::dump(void) const
{
    for (const auto &it : this->_mapComponentsType) {
        this->_mapComponents.at(it.first)->dump();
    }
}

Circuit::~Circuit()
{
    for (auto &it : this->_arrayTmp)
        delete it;
}
