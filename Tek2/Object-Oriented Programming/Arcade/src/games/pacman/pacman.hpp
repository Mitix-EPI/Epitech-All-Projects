/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <vector>
#include <string>
#include <list>
#include <math.h>
#include <cstdlib>
#include "IGameModule.hpp"
#include "UtilityClasses.hpp"

enum Content {
    PACMAN,
    WALL,
    GUM,
    PACGUM,
    PORTAL,
    GHOST1,
    GHOST2,
    GHOST3,
    GHOST4,
};

static std::vector<std::string> _contentName =
{
    "pacman", "wall", "wall", "wall", "wall",
       "ghost", "ghost", "ghost", "ghost"
};

static std::vector<char> _contentChar =
{
    'P', '#', 'd', 'O', '|',
       '1', '2', '3', '4'
};


class Pacman : public arcade::IGameModule {
    struct sNode {
        bool bObstacle = false;
        bool bVisited = false;
        float fGlobal;
        float fLocal;
        int x;
        int y;
        std::vector<sNode*> neighbours;
        sNode *parent;
    };
    public:
        Pacman();
        ~Pacman();
        void initialize(void);
        void createObject(Content content, std::size_t posx, std::size_t posy, Vector2i vec = Vector2i(0, 0), Vector2i size = Vector2i(0, 0), Vector2f scale = Vector2f(0, 0), Vector2i mult = Vector2i(0, 0), int level = 0);
        void initObjects(void);
        bool IAGhost(int content);
        void randomMove(int content);
        void movePacman();
        void moveOne(int x, int y, int content);
        void setRect();
        bool setPos();
        int checkSideTemp();
        int checkSide();
        void changeDirection();
        bool update(Vector2i mouse, char key);
        void updateScorePacmanEats(object::Object obj);
        float  distance(sNode* a, sNode* b);
        void reset(void);
        // HANDLE
        void handleMouseEvent(void);
        void handleKeyEvent(char key);
        // GET
        std::vector<object::Object> getObjects() {return this->_objects;};
        Settings getSetting(void) { return this->_settings; }
    private:
        std::vector<std::string> _map;
        std::vector<object::Object> _objects;
        std::size_t _scene;
        std::size_t _clock;
        std::size_t _side;
        std::vector<std::size_t> _sideGhost1;
        std::vector<Vector2i> _previousGhost1;
        std::vector<Vector2i> _positionGhosts;
        std::size_t _sideTemp;
        std::size_t _spritePos;
        Settings _settings;
        clock_t _time;
        sNode *_node = nullptr;
        sNode *_nodeStart = nullptr;
        sNode *_nodeEnd = nullptr;
        std::size_t _height = 0;
        std::size_t _width = 0;
        std::vector<char> _previousMove;
        std::vector<std::size_t> _previousDir;
        char _previousMovePacMan = 0;
        bool _stop = false;
        bool _restart = false;
        std::vector<int> _eatingGhost;
        std::vector<int> _ghostWait;
        std::vector<Vector2i> _startPos;
};

#endif /* !PACMAN_HPP_ */
