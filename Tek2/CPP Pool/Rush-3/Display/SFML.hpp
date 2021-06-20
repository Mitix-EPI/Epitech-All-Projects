/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "../MonitorCore/MonitorDisplay.hpp"


class BoxSFML {
    public:
        BoxSFML(float x, float y, sf::Color color, sf::Vector2f size, sf::Color filled = sf::Color::Black);
        ~BoxSFML();

        sf::RectangleShape &getRectangle(void) {return _rectangle;};
        sf::Vector2f getPos(void) {return _rectangle.getPosition();};
        void setPosition(const sf::Vector2f &pos) {_rectangle.setPosition(pos);};
        void setSize(const sf::Vector2f &size) { _rectangle.setSize(size);};

    protected:
        int _width;
        int _height;
        sf::Vector2i _pos;
        sf::RectangleShape _rectangle;

};

class SFML: public MonitorDisplay {
    public:
        SFML();
        ~SFML();

        void init(void);
        void run(void);
        void display(void);
        void update(void);
        void destroy(void);
        sf::Vector2f createVector(float x, float y) {return (sf::Vector2f(x, y));};
        void initCpu(void);
        void drawUser(void);
        void initTextTime(void);
        void initTextHost(void);
        void initTextNetwortk(void);
        void updateCpu(void);

    protected:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Text _to_display_host;
        sf::Text _toDisplayTime;
        sf::Text _toDisplayNetwork;
        sf::Font _font;
        sf::RectangleShape _bar;
        std::vector <BoxSFML *> _boxes;
        std::vector <BoxSFML *> _cpus_fixed;
        std::vector <BoxSFML *> _cpus_dynamic;
        sf::Time _timeClock;
        sf::Clock _clock;
        sf::Clock _clock_cpu;
        float milliseconds = 1000000.0;
        std::vector <sf::Text> _cpuNb;
        std::vector <sf::Text> _perc;

};

#endif /* !SFML_HPP_ */
