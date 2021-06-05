/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Snake
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(): _settings("musicPath", "folderPath")
{
    std::ifstream file;
    std::string content;
    
    file.open("assets/nibbler/background.txt");
    if (!file) {
        std::cerr << "File is not open" << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty" << std::endl;
        return;
    }
    for (int lineNbr = 0; std::getline(file, content); lineNbr++)
        this->_map.push_back(content);
    this->initObjects();
    this->_clock = std::chrono::system_clock::now();
    this->_clockApple = std::chrono::system_clock::now();
    this->initSettings();
    this->_lastEatPoint = std::chrono::system_clock::now();
}

void Nibbler::initSettings(void)
{
    // TODO
    this->_settings.setScore(0);
}

void Nibbler::createObject(std::string filepath, Content content, float posx, float posy, Vector2i vec, Vector2i size, Vector2i scale, int level, Direction direction)
{
    object::Object obj;
    object::Sprite_t sprite;
    obj.setContent(content);
    sprite._filePath = filepath;
    sprite._rectSize.setX(vec.getX());
    sprite._rectSize.setY(vec.getY());
    sprite._sizeSquare.setX(size.getX());
    sprite._sizeSquare.setY(size.getY());
    sprite._scale.setX(scale.getX());
    sprite._scale.setY(scale.getY());
    sprite._extra.set(0,0);
    sprite._mult = Vector2i(sprite._scale.getX() * sprite._sizeSquare.getX(), sprite._scale.getY() * sprite._sizeSquare.getY());
    if (content == TAIL) {
        obj.setColor(Vector3i(0, 0, 255));
        sprite._charNcurse = 'O';
    }
    if (content == BODY) {
        obj.setColor(Vector3i(0, 0, 255));
        sprite._charNcurse = 'O';
    }
    if (content == APPLE) {
        obj.setColor(Vector3i(255, 0, 0));
        sprite._charNcurse = '*';
    }
    if (content == WALL) {
        sprite._charNcurse = '#';
        obj.setColor(Vector3i(255, 255, 255));
    }
    if (content == GROUND) {
        obj.setColor(Vector3i(0, 255, 0));
        sprite._charNcurse = '-';
    }
    if (content == GOLDENAPPLE) {
        obj.setColor(Vector3i(255,255,0));
        sprite._charNcurse = '*';
    }
    if (content == NIBBLER) {
        switch (direction)
        {
        case UP:
            sprite._charNcurse = '^';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        case DOWN:
            sprite._charNcurse = 'v';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        case LEFT:
            sprite._charNcurse = '<';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        case RIGHT:
            sprite._charNcurse = '>';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        }
    }
    obj.setSprite(sprite);
    obj.setActive(true);
    int x = round(posx);
    int y = round(posy);
    obj.setPos(Vector2i(x, y));
    obj.setLevel(level);
    this->_objects.push_back(obj);
}

object::Object Nibbler::returnObject(std::string filepath, Content content, float posx, float posy, Vector2i vec, Vector2i size, Vector2i scale, int level, Direction direction)
{
    object::Object obj;
    object::Sprite_t sprite;
    obj.setContent(content);
    sprite._filePath = filepath;
    sprite._rectSize.setX(vec.getX());
    sprite._rectSize.setY(vec.getY());
    sprite._sizeSquare.setX(size.getX());
    sprite._sizeSquare.setY(size.getY());
    sprite._scale.setX(scale.getX());
    sprite._scale.setY(scale.getY());
    sprite._extra.set(0,0);
    sprite._mult = Vector2i(sprite._scale.getX() * sprite._sizeSquare.getX(), sprite._scale.getY() * sprite._sizeSquare.getY());
    if (content == TAIL) {
        obj.setColor(Vector3i(0, 0, 255));
        sprite._charNcurse = 'O';
    }
    if (content == BODY) {
        obj.setColor(Vector3i(0, 0, 255));
        sprite._charNcurse = 'O';
    }
    if (content == APPLE) {
        obj.setColor(Vector3i(255, 0, 0));
        sprite._charNcurse = '*';
    }
    if (content == WALL) {
        sprite._charNcurse = '#';
        obj.setColor(Vector3i(255, 255, 255));
    }
    if (content == GROUND) {
        obj.setColor(Vector3i(0, 255, 0));
        sprite._charNcurse = '-';
    }
    if (content == GOLDENAPPLE) {
        obj.setColor(Vector3i(255,255,0));
        sprite._charNcurse = '*';
    }
    if (content == NIBBLER) {
        switch (direction)
        {
        case UP:
            sprite._charNcurse = '^';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        case DOWN:
            sprite._charNcurse = 'v';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        case LEFT:
            sprite._charNcurse = '<';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        case RIGHT:
            sprite._charNcurse = '>';
            obj.setColor(Vector3i(0, 0, 255));
            break;
        }
    }
    obj.setSprite(sprite);
    obj.setActive(true);
    int x = round(posx);
    int y = round(posy);
    obj.setPos(Vector2i(x, y));
    obj.setLevel(level);
    return obj;
}

void Nibbler::initObjects(void)
{
    for (std::size_t y = 0; y < this->_map.size(); y++) {
        for (std::size_t x = 0; x < this->_map[y].size(); x++) {
            float xfloat = x;
            float yfloat = y;
            SnakeBody part;
            switch (this->_map[y][x])
            {
            case '1':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 0), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat, yfloat, Vector2i(96, 0), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '2':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat, yfloat, Vector2i(56, 16), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '3':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat, yfloat, Vector2i(72, 16), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '4':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat, yfloat, Vector2i(80, 16), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '5':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", WALL, xfloat, yfloat, Vector2i(64, 16), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->walls.push_back(Vector2i(x, y));
                break;
            case '#':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                break;
            case 'P':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", NIBBLER, xfloat, yfloat , Vector2i(32, 24), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->indexHead = this->_objects.size() - 1;
                posHead = Vector2i(x, y);
                part = SnakeBody(Vector2i(xfloat, yfloat), RIGHT, this->_objects.size() - 1, NIBBLER);
                this->_snake.insert(this->_snake.begin(), part);
                break;
            case 'B':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", APPLE, xfloat, yfloat , Vector2i(48, 0), Vector2i(8, 8), Vector2i(4, 4), 1);
                this->fruits.push_back(Fruit(this->_objects.size() - 1, Vector2i(x, y)));
                break;
            case 'T':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", TAIL, xfloat, yfloat , Vector2i(40, 24), Vector2i(8, 8), Vector2i(4, 4), 1);
                break;
            case 'C':
                this->createObject("assets/nibbler/snake.png", GROUND, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 0);
                this->createObject("assets/nibbler/snake.png", BODY, xfloat, yfloat , Vector2i(40, 24), Vector2i(8, 8), Vector2i(4, 4), 1);
                part = SnakeBody(Vector2i(xfloat, yfloat), RIGHT, this->_objects.size() - 1, BODY);
                this->_snake.insert(this->_snake.begin(), part);
                break;
            case '0':
                this->createObject("assets/nibbler/snake.png", WALL, xfloat, yfloat , Vector2i(0, 8), Vector2i(8, 8), Vector2i(4, 4), 1);
                break;
            default:
                break;
            }
        }
        this->createObject("assets/nibbler/snake.png", GOLDENAPPLE, -10, -10 , Vector2i(48, 8), Vector2i(8, 8), Vector2i(4, 4), 1);
        this->fruits.push_back(Fruit(this->_objects.size() - 1, Vector2i(-10, -10)));
        this->direction = RIGHT;
    }
}

bool Nibbler::update(Vector2i pos, char key)
{
    auto tmp = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = tmp-this->_clock;
    int indexFruit = 0;
    if (!this->input)
        changeDirection(key);
    if (diff.count() >= this->refreshTime) {
        this->_clock = std::chrono::system_clock::now();
        updatePlayer();
        diff =  this->_clock - this->_clockApple;
        this->input = false;
        if (this->goldenApple == false && diff.count() > 5) {
            for (indexFruit = 0; indexFruit < this->fruits.size(); indexFruit++) {
                if (this->_objects[this->fruits[indexFruit]._index].getContent() == GOLDENAPPLE) {
                    newApple(this->fruits[indexFruit]._index, GOLDENAPPLE);
                    this->goldenApple = true;
                    break;
                }
            }
        }
        diff = this->_clock - this->_lastEatPoint;
        if (diff.count() > 0.9f && this->refreshTime > 0.04f) {
            this->refreshTime -= 0.005f;
            this->_lastEatPoint = std::chrono::system_clock::now();
        }
    }
    if (resetG) {
        resetG = false;
        return false;
    }

    return true;
}

bool Nibbler::checkSnake(Vector2i posHead)
{
    for (int i = 1; i < _snake.size(); i++) {
        if (_snake[i].getPos().getX() == posHead.getX() && _snake[i].getPos().getY() == posHead.getY()) {
            return true;
        }
    }
    return false;
}

void Nibbler::newApple(int indexFruit, Content type)
{
    std::vector<Vector2i> availablePos;
    for (int i = 0; i < this->_objects.size(); i++) {
        if (this->_objects[i].getLevel() == 0)
            availablePos.push_back(this->_objects[i].getPos());
    }
    for (int i = 0; i < this->_objects.size(); i++) {
        if (this->_objects[i].getLevel() == 1) {
            Vector2i posTmp = this->_objects[i].getPos();
            for (int y = 0; y < availablePos.size(); y++) {
                if (posTmp.getX() == availablePos[y].getX() && posTmp.getY() == availablePos[y].getY()) {
                    availablePos.erase(availablePos.begin()+y);
                }
            }
        }
    }
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0,availablePos.size() - 1);
    int random_variable = distribution(gen); 
    if (type == APPLE)
        this->_objects.at(indexFruit) = returnObject("assets/nibbler/snake.png", APPLE, availablePos[random_variable].getX(), availablePos[random_variable].getY() , Vector2i(48, 0), Vector2i(8, 8), Vector2i(4, 4), 1);
    else
        this->_objects.at(indexFruit) = returnObject("assets/nibbler/snake.png", GOLDENAPPLE, availablePos[random_variable].getX(), availablePos[random_variable].getY() , Vector2i(48, 8), Vector2i(8, 8), Vector2i(4, 4), 1);

    for (int i = 0; i < fruits.size(); i++) {
        if (fruits[i]._index == indexFruit) {
            fruits[i]._pos = availablePos[random_variable];
        }
    }
}

void Nibbler::createNewPart(int index)
{
    SnakeBody lastPart = this->_snake[this->_snake.size() - 1];
    int x = lastPart.getPos().getX();
    int y = lastPart.getPos().getY();
    Direction direction;
    if (lastPart.getDirection() == RIGHT) {
        x -= 1;
        direction = RIGHT;
    } else if (lastPart.getDirection() == LEFT) {
        x += 1;
        direction = LEFT;
    } else if (lastPart.getDirection() == UP) {
        y += 1;
        direction = UP;
    } else if (lastPart.getDirection() == DOWN) {
        y -= 1;
        direction = DOWN;
    }
    
    this->createObject("assets/nibbler/snake.png", BODY, x, y , Vector2i(40, 24), Vector2i(8, 8), Vector2i(4, 4), 1);
    this->_snake.push_back(SnakeBody(Vector2i(x, y), direction, this->_objects.size() - 1, BODY));
}

void Nibbler::updatePlayer()
{
    for (std::size_t i = (this->_snake.size() - 1); i > 0; i--) {
        this->_snake[i].updateSnake(this->_snake[i-1]);
    }
    this->_snake[0].updateSnake(this->direction);
    for (std::size_t i = 0; i < this->_snake.size(); i++) {
        int index = this->_snake[i].getIndex();
        moveNibbler(index, this->_snake[i].getDirection(), this->_snake[i]);
        if (i == 0)
            changeSpriteRect(this->_snake[i].getDirection(), index, this->_snake[i]);
        else 
            changeSpriteRect(this->_snake[i].getDirection(), index, this->_snake[i-1]);
        index-=2;
    }
    bool quit = checkwalls(this->_snake[0].getPos());
    int bonus = checkfruits(this->_snake[0].getPos());
    bool hitbox = checkSnake(this->_snake[0].getPos());
    if (hitbox == true)
        resetG = true;
    if (quit == true)
        resetG = true;
    if (bonus != 0) {
        createNewPart(bonus);

        this->_objects.at(bonus) = returnObject("assets/nibbler/snake.png", APPLE, -1, -1, Vector2i(48, 0), Vector2i(8, 8), Vector2i(4, 4), 1);
        indexFruit = bonus;
    }
    auto tmp = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = tmp-this->_clockApple;
    if (fruitDisp > 0) {
        newApple(indexFruit);
        fruitDisp--;
    }
    
}

void Nibbler::changeDirection(char key)
{
    Vector2i playerPos = this->_snake[0].getPos();
    switch (key)
    {
    case 'V':
        if (this->direction != UP && !(checkwalls(playerPos, 0, 1))) {
            this->direction = DOWN;
            this->input = true;
        }
        break;
    case '^':
        if (this->direction != DOWN && !(checkwalls(playerPos, 0, -1))) {
            this->direction = UP;
            this->input = true;
        }
        break;
    case '<':
        if (this->direction != RIGHT && !(checkwalls(playerPos, -1, 0))) {
            this->direction = LEFT;
            this->input = true;
        }
        break;
    case '>':
        if (this->direction != LEFT && !(checkwalls(playerPos, 1, 0))) {
            this->direction = RIGHT;
            this->input = true;
        }
        break;
    default:
        break;
    }
}

void Nibbler::changeHead(Direction direction, int index, int x, int y)
{
    switch (direction) {
        case DOWN:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x, y, Vector2i(24, 24), Vector2i(8, 8), Vector2i(4, 4), 1, direction);
            break;
        case UP:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x, y, Vector2i(8, 24), Vector2i(8, 8), Vector2i(4, 4), 1, direction);
            break;
        case RIGHT:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x, y, Vector2i(32, 24), Vector2i(8, 8), Vector2i(4, 4), 1, direction);
            break;
        case LEFT:
            this->_objects.at(index) = returnObject("assets/nibbler/snake.png", NIBBLER, x, y, Vector2i(16, 24), Vector2i(8, 8), Vector2i(4, 4), 1, direction);
            break;
        default:
            break;
    }
}

bool Nibbler::checkwalls(Vector2i posHead, int diffX, int diffY)
{
    for (int i = 0; i < walls.size(); i++) {
        if ((posHead.getX() + diffX) == walls[i].getX() && (posHead.getY() + diffY) == walls[i].getY())
            return true;
    }
    return false;
}

void Nibbler::goldenAppleEat(int index)
{
    createNewPart(index);
    createNewPart(index);
    this->_clockApple = std::chrono::system_clock::now();
    this->goldenApple = false;
    this->_objects.at(index) = returnObject("assets/nibbler/snake.png", GOLDENAPPLE, -10, -10, Vector2i(48, 8), Vector2i(8, 8), Vector2i(4, 4), 1);

}

int Nibbler::checkfruits(Vector2i posHead, int diffX, int diffY)
{
    for (int i = 0; i < fruits.size(); i++) {
        if ((posHead.getX() + diffX) == fruits[i]._pos.getX() && (posHead.getY() + diffY) == fruits[i]._pos.getY()) {
            this->_lastEatPoint = std::chrono::system_clock::now();
            if (this->refreshTime < 0.15f && this->_objects[fruits[i]._index].getContent() == APPLE) {
                this->refreshTime += 0.005f;
            } else if (this->_objects[fruits[i]._index].getContent() == GOLDENAPPLE) {
                this->refreshTime += 0.01f;
                if (this->refreshTime > 0.15f)
                    this->refreshTime = 0.15f;
            }
            if (this->_objects[fruits[i]._index].getContent() == APPLE) {
                this->_settings.setScore(this->_settings.getScore() + 100);
                this->fruitDisp++;
                return fruits[i]._index;
            } else {
                this->_settings.setScore(this->_settings.getScore() + 300);
                goldenAppleEat(fruits[i]._index);
                return 0;
            }
        }
    }
    return 0;
}


int getX(float scale, int pos, int size)
{
    int trueSize = size*scale;
    return (pos / trueSize);
}

void Nibbler::changeSpriteRect(Direction direction, int index, SnakeBody body)
{
    Vector2i scale = this->_objects[index].getSprite()._scale;
    Vector2i size = this->_objects[index].getSprite()._sizeSquare;
    Vector2i pos = this->_objects[index].getPos();
    int x = pos.getX();
    int y = pos.getY();

    switch (this->_objects[index].getContent()) {
        case NIBBLER:
            changeHead(direction, index, x, y);
            break;
        default:
            break;
    }

}

void Nibbler::moveNibbler(int index, Direction directionPart, SnakeBody body)
{
    Vector2i scale = this->_objects[index].getSprite()._scale;
    Vector2i size = this->_objects[index].getSprite()._sizeSquare;
    Vector2i pos = this->_objects[index].getPos();
    Vector2i newPos;
    switch (directionPart) {
        case UP:
            newPos.setX(pos.getX());
            newPos.setY(pos.getY() - 1);
            this->_objects[index].setPos(newPos);
            break;

        case DOWN:
            newPos.setX(pos.getX());
            newPos.setY(pos.getY() + 1);
            this->_objects[index].setPos(newPos);
            break;

        case LEFT:
            newPos.setX(pos.getX() - 1);
            newPos.setY(pos.getY());
            this->_objects[index].setPos(newPos);
            break;

        case RIGHT:
            newPos.setX(pos.getX() + 1);
            newPos.setY(pos.getY());
            this->_objects[index].setPos(newPos);
            break;
        default:
            break;
    }
}

void Nibbler::handleMouseEvent(void)
{

}

void Nibbler::handleKeyEvent(char key)
{

}
        

void Nibbler::move(int x, int y)
{

}

void Nibbler::reset()
{
    std::system("killall paplay");
    std::system("paplay assets/nibbler/nibbler_song.ogg & > /dev/null 2>&1");
    this->walls = {};
    this->fruits = {};
    this->_map.clear();
    this->_objects = {};
    this->_snake = {};
    this->refreshTime = 0.15f;
    this->input = false;
    this->resetG = false;
    direction = RIGHT;
    std::ifstream file;
    std::string content;
    file.open("assets/nibbler/background.txt");
    if (!file) {
        std::cerr << "File is not open" << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty" << std::endl;
        return;
    }
    for (int lineNbr = 0; std::getline(file, content); lineNbr++)
        this->_map.push_back(content);
    this->initObjects();
    this->_clock = std::chrono::system_clock::now();
    this->_clockApple = std::chrono::system_clock::now();
    this->createObject("assets/nibbler/snake.png", GOLDENAPPLE, -10, -10 , Vector2i(48, 8), Vector2i(8, 8), Vector2i(4, 4), 1);
    this->fruits.push_back(Fruit(this->_objects.size() - 1, Vector2i(-10, -10)));
    this->goldenApple = false;
    this->initSettings();
}

Nibbler::~Nibbler()
{
}