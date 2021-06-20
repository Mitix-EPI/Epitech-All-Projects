/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** SFML
*/

#include "SFML.hpp"
#include <cmath>

BoxSFML::BoxSFML(float x, float y, sf::Color color, sf::Vector2f size, sf::Color filled) {
    sf::Vector2f tmp(x, y);
    _rectangle.setPosition(tmp);
    _rectangle.setOutlineColor(color);
    _rectangle.setOutlineThickness(3.0);
    _rectangle.setSize(size);
    _rectangle.setFillColor(filled);
};

BoxSFML::~BoxSFML()
{

}

SFML::SFML(): MonitorDisplay()
{
    sf::VideoMode mode(800, 600);
    _window.create(mode, "MygKrellM");
}

SFML::~SFML()
{
}

// premier             
//deuxième

void SFML::init(void)
{
    _boxes.push_back(new BoxSFML(20, 20, sf::Color::Red, createVector(300, 100)));
    _boxes.push_back(new BoxSFML(20, 140, sf::Color::Blue, createVector(300, 300)));
    _boxes.push_back(new BoxSFML(350, 20, sf::Color::Green, createVector(300, 100)));
    _boxes.push_back(new BoxSFML(350, 140, sf::Color::Yellow, createVector(300, 300)));
    _font.loadFromFile("./Resources/Roboto/Roboto-Bold.ttf");
    _to_display_host.setFont(_font);
    _toDisplayTime.setFont(_font);
    _toDisplayNetwork.setFont(_font);
    initTextHost();
    initCpu();
    initTextTime();
    initTextNetwortk();
}

void SFML::initTextHost(void)
{
    std::string tmpHost;
    for (const auto &e: _user.getHostName()) {
        tmpHost = tmpHost + e + " ";
    }
    _to_display_host.setString("Username: " + _user.getUserName() + "\nHost: " + tmpHost + "\nVersion: " + _user.getOsVersion());
    _to_display_host.setPosition(createVector(30, 30));
    _to_display_host.setFillColor(sf::Color::White);
    _to_display_host.setCharacterSize(15);
}

void SFML::initTextTime(void)
{
    _toDisplayTime.setString("Date: " + _time.getActualDate() + "\nHour: " + _time.getActualTime() + "\nUptime: " + _time.getUptime());
    _toDisplayTime.setPosition(createVector(360, 30));
    _toDisplayTime.setFillColor(sf::Color::White);
    _toDisplayTime.setCharacterSize(15);
}

void SFML::initTextNetwortk(void)
{
    std::string tmpHost;
    for (const auto &e: _network.getData()) {
        tmpHost = tmpHost + e.name + "\n\tUP =>" + std::to_string(e.up) + "Kb/s\n\tDOWN => " + std::to_string(e.down) + "Kb/s\n";
    }
    _toDisplayNetwork.setString("NetWork Data Transfer: \n\n" + tmpHost);
    _toDisplayNetwork.setPosition(createVector(360, 150));
    _toDisplayNetwork.setFillColor(sf::Color::White);
    _toDisplayNetwork.setCharacterSize(15);
}

void SFML::initCpu(void)
{
    float posY = 170;
    _cpu.clearMap();
    _cpu.updateData();
    auto tab = _cpu.getCPUs();
    int i = 0;
    for (auto beg = tab.begin(); beg != tab.cend(); ++beg, posY += 33, i += 1) {
        _cpus_fixed.push_back(new BoxSFML(50, posY, sf::Color::Green, createVector(230, 20), sf::Color::Green));
        _cpuNb.push_back(sf::Text());
        _cpuNb[i].setFont(_font);
        _cpuNb[i].setPosition(createVector(30, posY));
        _cpuNb[i].setString(std::to_string(i));
        _cpuNb[i].setFillColor(sf::Color::White);
        _cpuNb[i].setCharacterSize(10);
        _perc.push_back(sf::Text());
        _perc[i].setFont(_font);
        _perc[i].setPosition(createVector(290, posY));
        _perc[i].setString("0%");
        _perc[i].setCharacterSize(10);
        _perc[i].setFillColor(sf::Color::White);
    }
    posY = 170;
    for (auto beg = tab.begin(); beg != tab.cend(); ++beg, posY += 33)
        _cpus_dynamic.push_back(new BoxSFML(50, posY, sf::Color::Green, createVector(0, 0), sf::Color::Red));
}

void SFML::display(void)
{
    _window.clear();
    for (const auto &e: _boxes)
        _window.draw(e->getRectangle());
    _window.draw(_to_display_host);
    _window.draw(_toDisplayTime);
    _window.draw(_toDisplayNetwork);
    for (const auto &e: _cpus_fixed)
        _window.draw(e->getRectangle());
    for (const auto &e: _cpus_dynamic)
        _window.draw(e->getRectangle());
    for (size_t i  = 0; i < _perc.size(); i += 1) {
        _window.draw(_perc[i]);
        _window.draw(_cpuNb[i]);
    }
    _window.display();
}

void SFML::run(void)
{
    init();
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
        }
        _timeClock = _clock.getElapsedTime();
        if (_timeClock.asMicroseconds() >= 100000.0) {
            update();
            _clock.restart();
        }
        _timeClock = _clock_cpu.getElapsedTime();
        if (_timeClock.asMicroseconds() >= 1000000.0) {
            updateCpu();
            _clock_cpu.restart();
        }
        display();
    }
}

void SFML::update(void)
{
    _user.updateData();
    _time.updateData();
    _network.updateData();
    std::string tmpHost;
    for (const auto &e: _user.getHostName()) {
        tmpHost = tmpHost + e + " ";
    }
    _to_display_host.setString("Username: " + _user.getUserName() + "\nHost: " + tmpHost + "\nVersion: " + _user.getOsVersion());
    _toDisplayTime.setString("Date: " + _time.getActualDate() + "\nHour: " + _time.getActualTime() + "\nUptime: " + _time.getUptime());
    for (const auto &e: _network.getData()) {
        tmpHost = tmpHost + e.name + "\n\tUP =>" + std::to_string(e.up) + "Kb/s\n\tDOWN => " + std::to_string(e.down) + "Kb/s\n";
    }
    _toDisplayNetwork.setString("NetWork Data Transfer: \n\n" + tmpHost);
}

void SFML::updateCpu(void)
{
    _cpu.clearMap();
    _cpu.updateData();
    auto tab = _cpu.getPercentage();
    for (size_t i = 0; i < tab.size(); ++i) {
        std::string tmp = "cpu" + std::to_string(i);
        float x = (round(tab[tmp.c_str()]) * 250) / 100;
        if (x > 250)
            x = 250;
        _perc[i].setString(std::to_string(static_cast<int>(round(tab[tmp.c_str()])))  + "%");
        _cpus_dynamic[i]->setSize(createVector(x, 20));
    }
}

void SFML::destroy(void)
{

}
