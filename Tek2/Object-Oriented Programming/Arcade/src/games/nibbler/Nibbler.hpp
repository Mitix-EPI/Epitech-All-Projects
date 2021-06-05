/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Nibller
*/
#include <vector>
#include <string>
#include <math.h>
#include "SnakeBody.hpp"
#include "IGameModule.hpp"
#include "UtilityClasses.hpp"
#include "Fruit.hpp"
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <random>

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

class SnakeBody;

enum Content {
    NIBBLER,
    WALL,
    APPLE,
    GOLDENAPPLE,
    GROUND,
    TAIL,
    BODY
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NOWHERE
};

class Nibbler : public arcade::IGameModule {
    public:
        Nibbler();
        ~Nibbler();
        bool update(Vector2i mouse, char key);
        void handleMouseEvent(void);
        void handleKeyEvent(char key);
        void initObjects(void);
        void move(int x, int y);
        void moveNibbler(int, Direction, SnakeBody);
        void changeDirection(char);
        object::Object returnObject(std::string filepath, Content content, float posx, float posy, Vector2i vec = Vector2i(0, 0), Vector2i size = Vector2i(0, 0), Vector2i scale = Vector2i(0, 0), int level = 0, Direction direction = RIGHT);
        void createObject(std::string filepath, Content content, float posx, float posy, Vector2i vec = Vector2i(0, 0), Vector2i size = Vector2i(0, 0), Vector2i scale = Vector2i(0, 0), int level = 0, Direction direction = RIGHT);
        std::vector<object::Object> getObjects() {return this->_objects;};
        void changeSpriteRect(Direction direction, int index, SnakeBody body);
        void changeHead(Direction direction, int index, int x, int y);
        void changeTail(Direction direction, int index, int x, int y);
        void changeBody(Direction direction, int index, int x, int y, SnakeBody body);
        void newApple(int indexFruit, Content type = APPLE);
        void goldenAppleEat(int index);
        bool checkSnake(Vector2i posHead);
        bool checkwalls(Vector2i posHead, int diffX = 0, int diffY = 0);
        int checkfruits(Vector2i posHead, int diffX = 0, int diffY = 0);
        Settings getSetting(void) { return this->_settings; }
        void updatePlayer();
        void createNewPart(int index);
        void initSettings(void);
        void reset(void);

    protected:
    private:
        std::vector<std::string> _map;
        std::vector<object::Object> _objects;
        std::size_t _scene;
        std::chrono::_V2::system_clock::time_point _clock;
        std::chrono::_V2::system_clock::time_point _clockApple;
        std::chrono::_V2::system_clock::time_point _lastEatPoint;
        Direction direction = RIGHT;
        std::vector<SnakeBody> _snake;
        int indexHead = 0;
        int fruitDisp = 0;
        int indexFruit = 0;
        bool goldenApple = false;
        Vector2i posHead;
        std::vector<Vector2i> walls;
        std::vector<Fruit> fruits;
        Settings _settings;
        float refreshTime = 0.15f;
        bool input = false;
        bool resetG = false;

};

#endif /* !SNAKE_HPP_ */
