/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pacman
*/

#include "pacman.hpp"

Pacman::Pacman() : _settings("musicPath", "assetsPath")
{
    this->initialize();
}

Pacman::~Pacman()
{

}

void Pacman::reset()
{
    std::system("paplay assets/pacman/pacman_song.ogg & > /dev/null 2>&1");
    this->initialize();
}

/**
 * Pacman 
 * Initialize variables
 * @param  {void} undefined : 
 */
void Pacman::initialize(void)
{
    std::ifstream file;
    std::string content;

    file.open("assets/pacman/background.txt");
    if (!file) {
        std::cerr << "File is not open" << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty" << std::endl;
        return;
    }
    if (!this->_map.empty())
        this->_map.clear();
    this->_height = 0;
    this->_width = 0;
    for (;std::getline(file, content); this->_height++)
        this->_map.push_back(content);
    this->_width = this->_map[0].size() - 2;
    this->_height -= 2;
    if (!this->_objects.empty())
        this->_objects.clear();
    this->initObjects();
    this->_settings.setScore(0);
    this->_settings.setMusicFolderPath("musicPath");
    this->_settings.setAssestFolderPath("assetsPath");
    std::map<char, std::string> keys = this->_settings.getKeys();
    keys.clear();
    this->_settings.setKeys(keys);
    this->_settings.setScene(scenes::GAME);
    this->_clock = 0;
    this->_side = 4;
    this->_sideTemp = 4;
    this->_spritePos = 0;
    this->_time = clock();
    this->_previousMovePacMan = 0;
    this->_stop = false;
    this->_eatingGhost.clear();
    this->_restart = false;
    this->_positionGhosts.clear();
    this->_previousGhost1.clear();
    this->_previousMove.clear();
    this->_sideGhost1.clear();
    this->_previousDir.clear();
    this->_ghostWait.clear();
    this->_startPos.clear();
    int count = 0;
    for (int i = GHOST1; i <= GHOST4; i++)
        for (int y = 0; y < this->_height; y++)
            for (int x = 0; x < this->_width; x++)
                if (this->_map[y + 1][x + 1] == _contentChar[i]) {
                    this->_positionGhosts.push_back(Vector2i(x, y));
                    this->_previousGhost1.push_back(Vector2i(0, 0));
                    this->_previousMove.push_back(0);
                    this->_sideGhost1.push_back(4);
                    this->_previousDir.push_back(0);
                    this->_eatingGhost.push_back(0);
                    this->_ghostWait.push_back(1000 + (count * 100));
                    this->_startPos.push_back(Vector2i(x, y));
                    count++;
                }
}

/**
 * Pacman 
 * Create Objects
 * @param  {Content} content  : 
 * @param  {std::size_t} posx : 
 * @param  {std::size_t} posy : 
 * @param  {Vector2i} vec     : 
 * @param  {Vector2i} size    : 
 * @param  {Vector2f} scale   : 
 * @param  {Vector2i} mult    : 
 * @param  {int} level        : 
 */
void Pacman::createObject(Content content, std::size_t posx, std::size_t posy, Vector2i vec, Vector2i size, Vector2f scale, Vector2i mult, int level)
{
    object::Object obj;
    object::Sprite_t sprite;
    sprite._filePath = "assets/pacman/" + _contentName[content] + ".png";
    sprite._mult.setX(mult.getX());
    sprite._mult.setY(mult.getY());
    sprite._extra.set(0, 0);
    sprite._rectSize.setX(vec.getX());
    sprite._rectSize.setY(vec.getY());
    sprite._sizeSquare.setX(size.getX());
    sprite._sizeSquare.setY(size.getY());
    sprite._scale.setX(scale.getX());
    sprite._scale.setY(scale.getY());
    if (content == GHOST1) {
        obj.setColor(Vector3i(255, 0, 255));
        sprite._charNcurse = '1';
    }
    if (content == GHOST2) {
        obj.setColor(Vector3i(255, 0, 0));
        sprite._charNcurse = '2';
    }
    if (content == GHOST3) {
        obj.setColor(Vector3i(0, 255, 255));
        sprite._charNcurse = '3';
    }
    if (content == GHOST4) {
        obj.setColor(Vector3i(0, 0, 255));
        sprite._charNcurse = '4';
    }
    if (content == WALL) {
        sprite._charNcurse = '#';
        obj.setColor(Vector3i(255, 255, 255));
    }
    if (content == PACMAN) {
        sprite._charNcurse = 'P';
        obj.setColor(Vector3i(255, 255, 0));
    }
    if (content == GUM) {
        sprite._charNcurse = '-';
        obj.setColor(Vector3i(255, 255, 0));
    }
    if (content == PACGUM) {
        sprite._charNcurse = 'o';
        obj.setColor(Vector3i(255, 255, 255));
    }
    if (content == PORTAL) {
        sprite._charNcurse = '|';
        obj.setColor(Vector3i(0, 0, 0));
    }
    obj.setSprite(sprite);
    obj.setActive(true);
    obj.setPos(Vector2i(posx, posy));
    obj.setLevel(-1);
    obj.setContent(content);
    this->_objects.push_back(obj);
}

/**
 * Pacman 
 * Initialize objects
 * @param  {void} undefined : 
 */
void Pacman::initObjects(void)
{
    for (std::size_t y = 1; y < this->_map.size() - 1; y++) {
        for (std::size_t x = 1; x < this->_map[y].size() - 1; x++) {
            if (this->_map[y][x] == '#') {
                std::unordered_map<std::string, char> square;
                square["uleft"] = this->_map[y - 1][x - 1];
                square["left"] = this->_map[y][x - 1];
                square["dleft"] = this->_map[y + 1][x - 1];
                square["down"] = this->_map[y + 1][x];
                square["dright"] = this->_map[y + 1][x + 1];
                square["right"] = this->_map[y][x + 1];
                square["uright"] = this->_map[y - 1][x + 1];
                square["up"] = this->_map[y - 1][x];
                this->createObject(WALL, (x - 1), (y - 1), createWalls(square), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
            } else if (this->_map[y][x] == 'd')
                this->createObject(GUM, (x - 1), (y - 1), Vector2i(117, 18), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
            else if (this->_map[y][x] == 'O')
                this->createObject(PACGUM, (x - 1), (y - 1), Vector2i(135, 18), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
            else if (this->_map[y][x] == 'P')
                this->createObject(PACMAN, (x - 1), (y - 1), Vector2i(0, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '1')
                this->createObject(GHOST1, (x - 1), (y - 1), Vector2i(0, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '2')
                this->createObject(GHOST2, (x - 1), (y - 1), Vector2i(24, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '3')
                this->createObject(GHOST3, (x - 1), (y - 1), Vector2i(48, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] == '4')
                this->createObject(GHOST4, (x - 1), (y - 1), Vector2i(72, 0), Vector2i(24, 24), Vector2f(1, 1), Vector2i(3*8, 3*8), 1);
            else if (this->_map[y][x] >= '|')
                this->createObject(PORTAL, (x - 1), (y - 1), Vector2i(126, 18), Vector2i(8, 8), Vector2f(3, 3), Vector2i(3*8, 3*8));
        }
    }
}

/**
 * Pacman 
 * Distance between 2 nodes
 * @param  {sNode*} a : 
 * @param  {sNode*} b : 
 * @return {float}    : 
 */
float  Pacman::distance(sNode* a, sNode* b)
{
    return sqrtf((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
}

void Pacman::randomMove(int content)
{
    Vector2i position(this->_positionGhosts[content - GHOST1]);
    std::vector<Vector2i> validPos;
    if (this->_map[position.getY() + 1 + 1][position.getX() + 1] != '#' && this->_previousDir[content - GHOST1] != 3)
        validPos.push_back(Vector2i(position.getX(), position.getY() + 1));
    if (this->_map[position.getY()][position.getX() + 1] != '#' && this->_previousDir[content - GHOST1] != 1)
        validPos.push_back(Vector2i(position.getX(), position.getY() - 1));
    if (this->_map[position.getY() + 1][position.getX() + 1 + 1] != '#' && this->_previousDir[content - GHOST1] != 0)
        validPos.push_back(Vector2i(position.getX() + 1, position.getY()));
    if (this->_map[position.getY() + 1][position.getX()] != '#' && this->_previousDir[content - GHOST1] != 2)
        validPos.push_back(Vector2i(position.getX() - 1, position.getY()));
    if (validPos.size() == 0)
        return;
    for (int i = 0; i < validPos.size(); i++)
        // std::cout << "pos : (" << validPos[i].getX() << ", " << validPos[i].getY() << ")." << std::endl;
    std::srand(std::time(nullptr));
    int random_variable = std::rand()/((RAND_MAX + 1u)/validPos.size());
    position.set(validPos[random_variable]);
    Vector2i pos(0, 0);
    int i = 0;
    for (; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == content)
            break;
    pos = this->_objects[i].getPos();
    this->_map[pos.getY() + 1][pos.getX() + 1] = (this->_previousMove[content - GHOST1] == 0 ? ' ' : this->_previousMove[content - GHOST1]);
    if (position.getX() > pos.getX()) {
        this->_sideGhost1[content - GHOST1] = 0;
        this->_previousDir[content - GHOST1] = 2;
    }
    if (position.getY() < pos.getY()) {
        this->_sideGhost1[content - GHOST1] = 1;
        this->_previousDir[content - GHOST1] = 3;
    }
    if (position.getX() < pos.getX()) {
        this->_sideGhost1[content - GHOST1] = 2;
        this->_previousDir[content - GHOST1] = 0;
    }
    if (position.getY() > pos.getY()) {
        this->_sideGhost1[content - GHOST1] = 3;
        this->_previousDir[content - GHOST1] = 1;
    }
    pos.addX(position.getX() - pos.getX());
    pos.addY(position.getY() - pos.getY());
    if (this->_map[pos.getY() + 1][pos.getX() + 1] == 'P') {
        pos.set(this->_startPos[content - GHOST1]);
        this->_ghostWait[content - GHOST1] = 1000;
        this->_previousDir[content - GHOST1] = 4;
        this->_previousMove[content - GHOST1] = 4;
        this->_eatingGhost[content - GHOST1] = 0;
        this->_sideGhost1[content - GHOST1] = 4;
    }
    this->_previousDir[content - GHOST1] = 0;
    this->_objects[i].setPos(pos);
    this->_previousMove[content - GHOST1] = this->_map[pos.getY() + 1][pos.getX() + 1];
    this->_map[pos.getY() + 1][pos.getX() + 1] = _contentChar[content];
    this->_positionGhosts[content - GHOST1] = pos;
    object::Sprite_t sprite;
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == content)
            sprite = this->_objects[i].getSprite();
    if (this->_eatingGhost[content - GHOST1] > 0)
        sprite._rectSize.set(96, 0);
    else
        sprite._rectSize.set(0, 0);
        // sprite._rectSize.set((content - 5) * 24, 0);
    sprite._extra.set(0, 0);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == content)
            this->_objects[i].setSprite(sprite);
}

/**
 * Pacman 
 * A* algorithm
 * @return  {bool}  : 
 */
bool Pacman::IAGhost(int content)
{
    if (this->_eatingGhost[content - GHOST1] > 0) {
        this->randomMove(content);
        return false;
    }
    this->_nodeStart = nullptr;
    this->_nodeEnd = nullptr;
    this->_node = nullptr;
    this->_node = new sNode[this->_width * this->_height];
    // // std::cout << "set nodes for " << std::to_string(content) << std::endl;
    for (int y = 0; y < this->_height; y++)
        for (int x = 0; x < this->_width; x++) {
            this->_node[x * this->_height + y].x = x;
            this->_node[x * this->_height + y].y = y;
            // this->_node[x * this->_height + y].bObstacle = (this->_map[y + 1][x + 1] == '#' ? true : false);
            bool obs = false;
            if (this->_map[y + 1][x + 1] == '#')
                obs = true;
            for (int i = GHOST1; i <= GHOST4; i++)
                if (this->_map[y + 1][x + 1] == _contentChar[i] && i != content)
                    obs = true;
            this->_node[x * this->_height + y].bObstacle = obs;
            this->_node[x * this->_height + y].bVisited = false;
            this->_node[x * this->_height + y].parent = nullptr;
            this->_node[x * this->_height + y].fGlobal = INFINITY;
            this->_node[x * this->_height + y].fLocal = INFINITY;
        }
    // // std::cout << "set neighbours for " << std::to_string(content) << std::endl;
    for (int y = 0; y < this->_height; y++)
        for (int x = 0; x < this->_width; x++) {
            if (x > 0)
                this->_node[x * this->_height + y].neighbours.push_back(&this->_node[(x - 1) * this->_height + (y + 0)]);
            if (x < this->_width - 1)
                this->_node[x * this->_height + y].neighbours.push_back(&this->_node[(x + 1) * this->_height + (y + 0)]);
            if (y > 0)
                this->_node[x * this->_height + y].neighbours.push_back(&this->_node[(x + 0) * this->_height + (y - 1)]);
            if (y < this->_height + 1)
                this->_node[x * this->_height + y].neighbours.push_back(&this->_node[(x + 0) * this->_height + (y + 1)]);
        }
    // // std::cout << "set nodeEnd and start " << std::to_string(content) << std::endl;
    for (int y = 0; y < this->_height; y++) {
        for (int x = 0; x < this->_width; x++) {
            // if (this->_positionGhosts[content - GHOST1] == Vector2i(x, y))
            //     std::cout << _contentChar[content];
            // else
            //     std::cout << this->_map[y + 1][x + 1];
            if (this->_map[y + 1][x + 1] == 'P')
                this->_nodeEnd = &this->_node[x * this->_height + y];
        }
        // std::cout << std::endl;
    }
    // std::cout << std::endl;
    Vector2i posGhost = this->_positionGhosts[content - GHOST1];
    this->_nodeStart = &this->_node[posGhost.getX() * this->_height + posGhost.getY()];
    sNode *nodeCurrent = this->_nodeStart;
    this->_nodeStart->fLocal = 0.0f;
    this->_nodeStart->fGlobal = this->distance(this->_nodeStart, this->_nodeEnd);
    std::list<sNode*> listNotTestedNodes;
    listNotTestedNodes.push_back(this->_nodeStart);
    // // std::cout << "A* algorihtme " << std::to_string(content) << std::endl;
    while (!listNotTestedNodes.empty() && nodeCurrent != this->_nodeEnd) {
        listNotTestedNodes.sort([](const sNode* lhs, const sNode* rhs){return lhs->fGlobal < rhs->fGlobal;});
        while(!listNotTestedNodes.empty() && listNotTestedNodes.front()->bVisited)
            listNotTestedNodes.pop_front();
        if (listNotTestedNodes.empty())
            break;
        nodeCurrent = listNotTestedNodes.front();
        nodeCurrent->bVisited = true;
        for (auto nodeNeighbour : nodeCurrent->neighbours) {
            if (!nodeNeighbour->bVisited && nodeNeighbour->bObstacle == 0)
                listNotTestedNodes.push_back(nodeNeighbour);
            float fPossiblyLowerGoal = nodeCurrent->fLocal + this->distance(nodeCurrent, nodeNeighbour);
            if (fPossiblyLowerGoal < nodeNeighbour->fLocal) {
                nodeNeighbour->parent = nodeCurrent;
                nodeNeighbour->fLocal = fPossiblyLowerGoal;
                nodeNeighbour->fGlobal = nodeNeighbour->fLocal + this->distance(nodeNeighbour, this->_nodeEnd);
            }
        }
    }
    // // std::cout << "check if you have arrived " << std::to_string(content) << std::endl;
    if (this->_nodeEnd->parent == this->_nodeStart) {
        return true;
    }
    // // std::cout << "set position " << std::to_string(content) << std::endl;
    if (this->_nodeEnd != nullptr && this->_nodeEnd->parent != nullptr && this->_nodeEnd->parent != this->_nodeStart) {
        sNode *p = this->_nodeEnd;
        sNode *move = nullptr;
        // // std::cout << "get correct p " << std::to_string(content) << std::endl;
        for (;p->parent != this->_nodeStart; p = p->parent)
            if (p->parent->parent == this->_nodeStart)
                move = p;
        int i = 0;
        Vector2i pos(0, 0);
        // // std::cout << "get position ghost " << std::to_string(content) << std::endl;
        for (; i < this->_objects.size(); i++)
            if (this->_objects[i].getContent() == content)
                break;
        pos = this->_objects[i].getPos();
        this->_map[pos.getY() + 1][pos.getX() + 1] = (this->_previousMove[content - GHOST1] == 0 ? ' ' : this->_previousMove[content - GHOST1]);
        // // std::cout << "pos : (" << std::to_string(pos.getY()) << ", " << std::to_string(pos.getX()) << ")." << std::endl;
        this->_previousGhost1[content - GHOST1].set(pos);
        // // std::cout << "set move " << std::to_string(content) << std::endl;
        if (move) {
            if (move->x > p->x) {
                this->_sideGhost1[content - GHOST1] = 0;
                this->_previousDir[content - GHOST1] = 2;
            }
            if (move->y < p->y) {
                this->_sideGhost1[content - GHOST1] = 1;
                this->_previousDir[content - GHOST1] = 3;
            }
            if (move->x < p->x) {
                this->_sideGhost1[content - GHOST1] = 2;
                this->_previousDir[content - GHOST1] = 0;
            }
            if (move->y > p->y) {
                this->_sideGhost1[content - GHOST1] = 3;
                this->_previousDir[content - GHOST1] = 1;
            }
        } else
            this->_sideGhost1[content - GHOST1] = 4;
        // // std::cout << "set first pos " << std::to_string(content) << std::endl;
        pos.addX(p->x - pos.getX());
        pos.addY(p->y - pos.getY());
        this->_objects[i].setPos(pos);
        // // std::cout << "set previous move " << std::to_string(content) << std::endl;
        this->_previousMove[content - GHOST1] = this->_map[pos.getY() + 1][pos.getX() + 1];
        // // std::cout << "set new pos " << std::to_string(content) << std::endl;
        this->_map[pos.getY() + 1][pos.getX() + 1] = _contentChar[content];
        // // std::cout << "set position in vector " << std::to_string(content) << std::endl;
        this->_positionGhosts[content - GHOST1] = pos;
        object::Sprite_t sprite;
        // // std::cout << "get sprite " << std::to_string(content) << std::endl;
        for (std::size_t i = 0; i < this->_objects.size(); i++)
            if (this->_objects[i].getContent() == content)
                sprite = this->_objects[i].getSprite();
        if (this->_eatingGhost[content - GHOST1] > 0)
            sprite._rectSize.set(96, 0);
        else
            sprite._rectSize.set((content - 5) * 24, 0);
        sprite._extra.set(0, 0);
        for (std::size_t i = 0; i < this->_objects.size(); i++)
            if (this->_objects[i].getContent() == content)
                this->_objects[i].setSprite(sprite);
    }
    // // std::cout << "End IA " << std::to_string(content) << std::endl;

    return false;
}

/**
 * Pacman 
 * Move Pacman 1 pixel by 1 pixel
 * @param  {int} xpos : 
 * @param  {int} ypos : 
 */
void Pacman::moveOne(int xpos, int ypos, int content)
{
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == content) {
            object::Sprite_t sprite = this->_objects[i].getSprite();
            sprite._extra.addX(xpos);
            sprite._extra.addY(ypos);
            this->_objects[i].setSprite(sprite);
        }
}

/**
 * Pacman 
 * Move pacman based on the direction
 */
void Pacman::movePacman()
{
    if (this->_side == 0)
        this->moveOne(1, 0, PACMAN);
    else if (this->_side == 1)
        this->moveOne(0, -1, PACMAN);
    else if (this->_side == 2)
        this->moveOne(-1, 0, PACMAN);
    else if (this->_side == 3)
        this->moveOne(0, 1, PACMAN);
    for (int i = GHOST1; i <= GHOST4; i++) {
        if (this->_sideGhost1[i - GHOST1] == 0)
            this->moveOne(1, 0, i);
        else if (this->_sideGhost1[i - GHOST1] == 1)
            this->moveOne(0, -1, i);
        else if (this->_sideGhost1[i - GHOST1] == 2)
            this->moveOne(-1, 0, i);
        else if (this->_sideGhost1[i - GHOST1] == 3)
            this->moveOne(0, 1, i);
    }
}

/**
 * Pacman 
 * Set's position of Pacman
 * Removes gums from _objects and _map
 * Teleports Pacman if need be
 * @return {bool}  : 
 */
bool Pacman::setPos()
{
    Vector2i pos(0, 0);
    Vector2i tempPos(0, 0);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            pos.set(this->_objects[i].getPos());
    tempPos = pos;
    if (this->_side == 0)
        pos.addX(1);
    else if (this->_side == 1)
        pos.addY(-1);
    else if (this->_side == 2)
        pos.addX(-1);
    else if (this->_side == 3)
        pos.addY(1);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN) {
            //If Portal
            if (this->_previousMovePacMan == '|') {
                Vector2i position(0, 0);
                bool end = false;
                // std::cout << "map 2 : " << std::endl;
                for (int y = 0; y < this->_height; y++) {
                    for (int x = 0; x < this->_width; x++) {
                        // std::cout << this->_map[y + 1][x + 1];
                        if (this->_map[y + 1][x + 1] == '|')
                            position.set(x, y);
                    }
                    // std::cout << std::endl;
                }
                // std::cout << std::endl;
                this->_map[tempPos.getY() + 1][tempPos.getX() + 1] = '|';
                this->_previousMovePacMan = '^';
                // // std::cout << "pos : (" << std::to_string(position.getY()) << ", " << std::to_string(position.getX()) << ")." << std::endl;
                this->_map[position.getY() + 1][position.getX() + 1] = 'P';
                pos.set(position.getX(), position.getY());
            } else {
                //Set Map char
                this->_map[tempPos.getY() + 1][tempPos.getX() + 1] = (this->_previousMovePacMan == 0 ? ' ' : (this->_previousMovePacMan == '^' ? '|' : this->_previousMovePacMan));
                this->_previousMovePacMan = this->_map[pos.getY() + 1][pos.getX() + 1];
                //Delete 'd' from map and objects
                if (this->_previousMovePacMan == 'd') {
                    for (std::size_t j = 0; j < this->_objects.size(); j++)
                        if (this->_objects[j].getPos() == pos) {
                            this->_objects[j].setLevel(-1);
                            this->updateScorePacmanEats(this->_objects[j]);
                        }
                    this->_previousMovePacMan = ' ';
                }
                if (this->_previousMovePacMan == 'O') {
                    for (std::size_t j = 0; j < this->_objects.size(); j++)
                        if (this->_objects[j].getPos() == pos) {
                            this->_objects[j].setLevel(-1);
                            this->updateScorePacmanEats(this->_objects[j]);
                        }
                    for (int content = GHOST1; content <= GHOST4; content++)
                        this->_eatingGhost[content - GHOST1] = 1000;
                    this->_previousMovePacMan = ' ';
                }
                for (int content = GHOST1; content <= GHOST4; content++) {
                    if (this->_previousMovePacMan == _contentChar[content]) {
                        if (this->_eatingGhost[content - GHOST1] > 0) {
                            for (std::size_t j = 0; j < this->_objects.size(); j++)
                                if (this->_objects[j].getContent() == content) {
                                    this->_objects[j].setPos(Vector2i(this->_startPos[content - GHOST1]));
                                    this->_map[this->_startPos[content - GHOST1].getY() + 1][this->_startPos[content - GHOST1].getX() + 1] = _contentChar[content];
                                    this->_positionGhosts[content - GHOST1].set(this->_startPos[content - GHOST1]);
                                }
                            this->_ghostWait[content - GHOST1] = 1000;
                            this->_previousDir[content - GHOST1] = 4;
                            this->_previousMove[content - GHOST1] = 4;
                            this->_eatingGhost[content - GHOST1] = 0;
                            this->_sideGhost1[content - GHOST1] = 4;
                            this->_previousMovePacMan = ' ';
                        } else {
                            return true;
                        }
                    }
                }
                this->_map[pos.getY() + 1][pos.getX() + 1] = 'P';
            }
            //Set Pacman Pos
            object::Sprite_t sprite = this->_objects[i].getSprite();
            sprite._extra.set(0, 0);
            this->_objects[i].setSprite(sprite);
            this->_objects[i].setPos(pos);
        }
    return false;
}

/**
 * Pacman 
 * Set Pacman sprite rectangle
 * based on the direction of the pacman
 */
void Pacman::setRect()
{
    object::Sprite_t sprite;
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            sprite = this->_objects[i].getSprite();
    if (this->_side == 0)
        sprite._rectSize.set(0, 0);
    else if (this->_side == 1)
        sprite._rectSize.set(24, 0);
    else if (this->_side == 2)
        sprite._rectSize.set(48, 0);
    else if (this->_side == 3)
        sprite._rectSize.set(72, 0);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            this->_objects[i].setSprite(sprite);
}

/**
 * Pacman 
 * Checks the next direction in which the pacman will go
 * @return  {int} : 
 */
int Pacman::checkSideTemp()
{
    Vector2i pos(0, 0);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            pos = this->_objects[i].getPos();
    if (this->_sideTemp == 0)
        pos.addX(1);
    else if (this->_sideTemp == 1)
        pos.addY(-1);
    else if (this->_sideTemp == 2)
        pos.addX(-1);
    else if (this->_sideTemp == 3)
        pos.addY(1);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getPos() == pos) {
            if (this->_objects[i].getContent() == WALL) {
                // std::cout << std::endl;
                return 1;
            } else if (this->_objects[i].getContent() == PACMAN) {
                // std::cout << std::endl;
                return 2;
            }
        }
    // std::cout << std::endl;
    return 0;
}

/**
 * Pacman 
 * Checks the side which the pacman
 * is actually moving towards
 * @return {int}  : 
 */
int Pacman::checkSide()
{
    Vector2i pos(0, 0);
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getContent() == PACMAN)
            pos = this->_objects[i].getPos();
    if (this->_side == 0)
        pos.addX(1);
    else if (this->_side == 1)
        pos.addY(-1);
    else if (this->_side == 2)
        pos.addX(-1);
    else if (this->_side == 3)
        pos.addY(1);
    else if (this->_side == 4)
        return 0;
    for (std::size_t i = 0; i < this->_objects.size(); i++)
        if (this->_objects[i].getPos() == pos) {
            if (this->_objects[i].getContent() == WALL) {
                // std::cout << std::endl;
                return 1;
            } else if (this->_objects[i].getContent() == PACMAN) {
                // std::cout << std::endl;
                return 2;
            }
        }
    // std::cout << std::endl;
    return 0;
}

/**
 * Pacman 
 * Handles pacman direction
 */
void Pacman::changeDirection()
{
    if ((this->_sideTemp == this->_side && this->checkSideTemp() == 1) || (this->_sideTemp != this->_side && this->checkSideTemp() == 2) || (this->_sideTemp != this->_side && (this->checkSide() == 1 && this->checkSideTemp() == 1)))
        this->_side = 4;
    else if (this->_sideTemp != this->_side && this->checkSideTemp() == 0)
        this->_side = this->_sideTemp;
    this->setRect();
}

/**
 * Pacman 
 * Updates the pacman score as gums get eaten
 * @param  {object::Object} obj : 
 */
void Pacman::updateScorePacmanEats(object::Object obj)
{
    if (obj.getContent() == GUM) {
        this->_settings.setScore(this->_settings.getScore() + 10);
        return;
    }
    if (obj.getContent() == PACGUM) {
        this->_settings.setScore(this->_settings.getScore() + 50);
        return;
    }
    if (obj.getContent() == GHOST1) {
        this->_settings.setScore(this->_settings.getScore() + 200);
        return;
    }
    if (obj.getContent() == GHOST2) {
        this->_settings.setScore(this->_settings.getScore() + 400);
        return;
    }
    if (obj.getContent() == GHOST3) {
        this->_settings.setScore(this->_settings.getScore() + 800);
        return;
    }
    if (obj.getContent() == GHOST4) {
        this->_settings.setScore(this->_settings.getScore() + 1600);
        return;
    }
}
/**
 * Pacman 
 * Update pacman
 * @param  {Vector2i} mouse : 
 * @param  {char} key       : 
 */
bool Pacman::update(Vector2i mouse, char key)
{
    if (this->_restart)
        this->reset();
    static bool music = false;
    if (this->_spritePos < this->_objects.size()) {
        int level = 0;
        if (this->_objects[this->_spritePos].getContent() == PACMAN ||
        this->_objects[this->_spritePos].getContent() == GHOST1 ||
        this->_objects[this->_spritePos].getContent() == GHOST2 ||
        this->_objects[this->_spritePos].getContent() == GHOST3 ||
        this->_objects[this->_spritePos].getContent() == GHOST4)
            level = 1;
        this->_objects[this->_spritePos].setLevel(level);
        this->_spritePos++;
        return true;
    }
    this->handleKeyEvent(key);
    if (this->_clock == 0)
        this->changeDirection();
    this->_clock++;
    // std::cout << std::to_string(this->_ghostWait[0]) << std::endl;
    for (int i = GHOST1; i <= GHOST4; i++) {
        if (this->_ghostWait[i - GHOST1] > 0)
            this->_ghostWait[i - GHOST1]--;
        if (this->_eatingGhost[i - GHOST1])
            this->_eatingGhost[i - GHOST1]--;
    }
    if (this->_clock == 24) {
        bool restart = this->setPos();
        if (restart) {
            this->_restart = true;
            return false;
        }
        for (int i = GHOST1; i <= GHOST4; i++) {
            if (this->_ghostWait[i - GHOST1] == 0)
                restart = this->IAGhost(i);
            if (restart) {
                this->_restart = true;
                return false;
            }
        }
        this->_clock = 0;
    } else if (this->_clock != 1)
        this->movePacman();
    return true;
}
/**
 * Pacman 
 * Handles Key events
 * @param  {char} key : 
 */
void Pacman::handleKeyEvent(char key)
{
    if (key == '>')
        this->_sideTemp = 0;
    else if (key == '<')
        this->_sideTemp = 2;
    else if (key == '^')
        this->_sideTemp = 1;
    else if (key == 'V')
        this->_sideTemp = 3;
}
/**
 * Pacman 
 * Handles mouse events
 * @param  {void} undefined : 
 */
void Pacman::handleMouseEvent(void)
{
}