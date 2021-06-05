#include <iostream>
#include "IDisplayModule.hpp"
#include "UtilityClasses.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "SdlFiles.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>


class SDL2: public IDisplayModule
{
    public:

        SDL2(int w, int h)
        {
            this->windowSize.set(w, h);
        }
        ~SDL2()
        {

        }

        void open()
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
                exit(84);
            if (TTF_Init() < 0)
                exit(84);
            if (IMG_Init(IMG_INIT_JPG) == 0) {
                exit(84);
            }
            if (IMG_Init(IMG_INIT_PNG) == 0) {
                exit(84);
            }
            this->window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowSize.getX(), this->windowSize.getY(), 0);
            if (!this->window) {
                std::cerr << "Window cannot be initialized" << std::endl;
                exit(84);
            }
            this->renderer = SDL_CreateRenderer(this->window, 0, 0);
            if (!this->renderer) {
                std::cerr << "Renderer cannot be initialized" << std::endl;
                exit(84);
            }
            isMenuInit = false;
            gamesTitle = {};
            otherText = {};
            allRect = {};
            libTitle = {};
            playerInfo = {};
            namePlayer = "";
            contentGame.clear();
            SDL_PollEvent(&event);
        }
        
        bool forceExitPoint()
        {
            if (this->event.type == SDL_QUIT)
                return true;
            return false;
        }
        
        std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs)
        {
            std::unordered_map<std::string, std::string> *strings = new std::unordered_map<std::string, std::string>;
            if (!isMenuInit) {
                createTexts(games, graphs);
                createRect();
                setLeaderBoard();
                isMenuInit = true;
            }
            if (namePlayer.size() != 3) {
                displayNameInput();
                otherText[2]->_text.append(namePlayer);
                otherText[2]->setText(otherText[2]->_text.c_str(), renderer);
                event.type = SDL_MOUSEBUTTONUP;
                (*strings)["play"] = (this->_play) ? "true" : "false";
                return strings;
            }
            SDL_RenderClear(this->renderer);
            SDL_PollEvent(&event);
            for (int i = 0; i < this->gamesTitle.size(); i++) {
                if (gamesTitle[i]->_Message_rect.y < this->windowSize.getY() - 100)
                    this->gamesTitle[i]->displayText(this->renderer);
            }
            for (int i = 0; i < this->libTitle.size(); i++) {
                if (libTitle[i]->_Message_rect.y < this->windowSize.getY() - 100)
                    this->libTitle[i]->displayText(this->renderer);
            }
            for (int i = 0; i < this->otherText.size(); i++) {
                if (otherText[i]->_Message_rect.y < this->windowSize.getY() - 100)
                    this->otherText[i]->displayText(this->renderer);
            }
            this->PlayButton->displayText(this->renderer);
            for (int i = 0; i < allRect.size(); i++) {
                allRect[i]->displayRect(renderer);
            }
            displayLeaderBoard();
            handleMenuEvent();
            SDL_RenderPresent(this->renderer);
            SDL_UpdateWindowSurface(this->window);
            (*strings)["name"] = namePlayer;
            (*strings)["game"] = game;
            (*strings)["graph"] = graph;
            (*strings)["play"] = (this->_play) ? "true" : "false";
            return strings;
        }

        Vector2i getEventClick()
        {
            Vector2i pos(-1,-1);
            if (this->event.type == SDL_MOUSEBUTTONDOWN) {
                pos.set(event.button.x,event.button.y);
                return (pos); 
            }
            return pos;
        }

        char getKeyboardEvent()
        {
            if (this->event.type == SDL_KEYDOWN) {
                char eventKey = this->event.key.keysym.sym;
                switch (eventKey) {
                    case 80:
                        return '<';
                        break;
                    case 81:
                        return 'V';
                        break;
                    case 79:
                        return '>';
                        break;
                    case 82:
                        return '^';
                        break;
                    default:
                        return this->event.key.keysym.sym;
                        break;
                };
            }
            return 0;
        }

        void close()
        {
            SDL_DestroyWindow(this->window);
            TTF_Quit();
            SDL_Quit();
            IMG_Quit();
        }

        void changeGame() 
        {
            contentGame = {};
        }

        void display(arcade::IGameModule *game)
        {
            SDL_RenderClear(this->renderer);
            SDL_PollEvent(&event);
            SDL_Color green = {50, 205, 50};
            std::string scoreText = "Score : " + std::to_string(game->getSetting().getScore());
            this->Score = new Text(scoreText.c_str(), "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green, 45);
            this->Score->setPos(this->windowSize.getX() / 2 - 360, this->windowSize.getY() - 200);
            if (this->_play) {
                this->_play = false;
                std::vector<object::Object> obj = game->getObjects();
                for (std::size_t i = 0; i < obj.size(); i++) {
                    std::string name = std::to_string(i) + std::to_string(obj[i].getContent());
                    spriteSDL sprite(obj[i], renderer);
                    contentGame[name] = sprite;
                    if (i != 0) {
                        std::string lastName = std::to_string(i-1) + std::to_string(obj[i-1].getContent());
                    }
                }
            }
            std::vector<object::Object> obj = game->getObjects();
            Vector2i scale;
            Vector2i size;
            Vector2i pos;
            for (int a = 0; a < 2; a++)
                for (std::size_t i = 0; i < obj.size(); i++)
                    if (obj[i].getLevel() == a) {
                        scale = obj[i].getSprite()._scale;
                        size = obj[i].getSprite()._sizeSquare;
                        pos = obj[i].getPos();
                        std::string name = std::to_string(i) + std::to_string(obj[i].getContent());
                        if (contentGame.find(name) != contentGame.end()) {
                            contentGame[name].setPos(pos);
                            contentGame[name].updateSprite(obj[i]);
                            contentGame[name].displaySprite(renderer);
                        } else {
                            std::string name = std::to_string(i) + std::to_string(obj[i].getContent());
                            spriteSDL sprite(obj[i], renderer);
                            contentGame[name] = sprite;
                            contentGame[name].displaySprite(renderer);
                        }
                    }
            this->Score->displayText(renderer);
            SDL_RenderPresent(this->renderer);
            SDL_UpdateWindowSurface(this->window);
            delete this->Score;
        }

    private:

        void displayLeaderBoard()
        {
            for (int i = 0; i < _leaderText[game].size(); i++) {
                _leaderText[game][i]->displayText(renderer);
            }
        }
        
        void createRect()
        {
            allRect.push_back(new Rect(100, 50, 400, this->windowSize.getY() - 100));
            allRect[0]->_selected = true;
            allRect.push_back(new Rect(this->windowSize.getX() - 450, 50, 400, this->windowSize.getY() - 100));
            allRect.push_back(new Rect(this->windowSize.getX() / 2 - 200, 400, 400, 400));
        }

        void createTexts(std::vector<std::string> games, std::vector<std::string> graphs)
        {
            SDL_Color white = {255, 255, 255};
            SDL_Color green = {50, 205, 50};
            int y = 100;
            for (int i = 0; i < games.size(); i++) {
                if (i == 0) {
                    this->gamesTitle.push_back(new Text(games[i].c_str(), "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green));
                    this->gamesTitle[i]->_selected = true;
                    this->game = this->gamesTitle[i]->_text;
                } else
                    this->gamesTitle.push_back(new Text(games[i].c_str(), "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, white));
                    
                gamesTitle[i]->setPos(200, y);
                y += 110;
            }
            y = 100;
            for (int i = 0; i < graphs.size(); i++) {
                if (i == 0) {
                    this->libTitle.push_back(new Text(graphs[i].c_str(), "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green));
                    this->libTitle[i]->_selected = true;
                    this->graph = this->libTitle[i]->_text;
                } else
                    this->libTitle.push_back(new Text(graphs[i].c_str(), "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, white));

                libTitle[i]->setPos(this->windowSize.getX() - 330, y);
                y += 110;
            }
            this->PlayButton = new Text("PLAY", "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, white, 45);
            this->PlayButton->setPos(this->windowSize.getX() / 2 - 95, this->windowSize.getY() - 200);
            this->PlayButton->setSelected(false, renderer);
            this->otherText.push_back(new Text("ARCADE", "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green, 65));
            this->otherText[0]->setPos(this->windowSize.getX() / 2 - 195, 200);
            this->otherText.push_back(new Text("HIGHSCORE", "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green, 40));
            this->otherText[1]->setPos(this->windowSize.getX() / 2 - 180, 350);
            this->otherText.push_back(new Text("PLAYER : ", "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, white, 40));
            this->otherText[2]->setPos(525, 50);
        }

        void checkLeft(std::vector<Text*> tmp)
        {
            if (allRect[0]->_selected) {
                gamesTitle = tmp;
                game = tmp[0]->_text;
            }
            else {
                libTitle = tmp;
                graph = tmp[0]->_text;
            }
        }

        int getPlayerName()
        {
            if (event.type == SDL_KEYDOWN && namePlayer.size() > 0) {
                if (event.key.keysym.sym == 8) {
                    namePlayer.pop_back();
                    return 0;
                }
            }
            if (event.type == SDL_TEXTINPUT && namePlayer.size() < 3)
                if (event.text.text[0] != 32 && isalnum(event.text.text[0])) {
                    namePlayer.append(event.text.text);
                    return 0;
                }
            return 1;
        }
        
        void displayNameInput()
        {
            SDL_Color green = {50, 205, 50};
            Text text = Text("PLAYER : ", "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green, 40);
            Text playerText = Text("---", "src/graphicals/sdl2/assets/ARCADE_N.TTF", this->renderer, green, 40);
            text.setPos(windowSize.getX() / 2 - 160, windowSize.getY() / 2 - 80);
            playerText.setPos(windowSize.getX() / 2 - 80, windowSize.getY() / 2);
            if (namePlayer.size() > 0) {
                playerText.setText(namePlayer.c_str(), this->renderer);
                playerText.setSize(playerText._Message_rect.w*namePlayer.size(), 40);
            }
            bool done = false;
            while (!done) {
                SDL_RenderClear(this->renderer);
                text.displayText(this->renderer);
                if (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        close();
                        exit(84);
                    }
                    if (getPlayerName() == 0) {
                        std::transform(namePlayer.begin(), namePlayer.end(),namePlayer.begin(), ::toupper);
                        for (int i = namePlayer.size(); i < 3; i++) {
                            namePlayer[i] = '-';
                            namePlayer[i+1] = '\0';
                        }
                        playerText.setText(namePlayer.c_str(), renderer);
                    }
                    if (event.type == SDL_KEYDOWN) {
                        if (event.key.keysym.sym == 13 && namePlayer.size() >= 3) {
                            done = true;
                        }
                    }
                }
                playerText.displayText(this->renderer);
                SDL_RenderPresent(this->renderer);
                SDL_UpdateWindowSurface(this->window);
            }
        }

        void setTextToUnselected(std::vector<Text*> texts)
        {
            for (int y = 0; y < texts.size(); y++) {
                if (texts[y]->_selected)
                    texts[y]->setSelected(false, renderer);
            }
            PlayButton->setSelected(false, renderer);

        }
        
        void handleMenuClickEvent()
        {
            Vector2i pos(0, 0);
            pos.set(this->event.button.x,event.button.y);
            for (int y = 0; y < allRect.size(); y++) {
                if (allRect[y]->_selected) {
                    allRect[y]->_selected = false;
                }
            }            
            for (int y = 0; y < allRect.size(); y++) {
                if (allRect[y]->_selected) {
                    allRect[y]->_selected = false;
                }
            }
            for (int i = 0; i < gamesTitle.size(); i++) {
                if (gamesTitle[i]->isCLickInRect(pos)) {
                    setTextToUnselected(gamesTitle);
                    gamesTitle[i]->setSelected(true, renderer);
                    this->game = gamesTitle[i]->_text;
                    // std::rotate(gamesTitle.begin(), gamesTitle.begin()+(i-1), gamesTitle.end());
                }
            }
            for (int i = 0; i < libTitle.size(); i++) {
                if (libTitle[i]->isCLickInRect(pos)) {
                    setTextToUnselected(libTitle);
                    libTitle[i]->setSelected(true, renderer);
                    this->graph = libTitle[i]->_text;
                    // std::rotate(gamesTitle.begin(), gamesTitle.begin()+(i-1), gamesTitle.end());
                }
            }
            if (PlayButton->isCLickInRect(pos)) {
                if (PlayButton->_selected == false) {
                    this->allRect[0]->_selected = false;
                    this->allRect[1]->_selected = false;
                    PlayButton->setSelected(true, renderer);
                    this->otherText[2]->setSelected(false, renderer);
                    event.type = SDL_MOUSEBUTTONUP;
                } else {
                    playerInfo.insert({game, graph});
                }
            }
        }

        void setLeaderBoard()
        {
            std::vector<Text*> texts;
            SDL_Color green = {50, 205, 50};
    
            for (int i = 0; i < gamesTitle.size(); i++) {
                _leader[gamesTitle[i]->_text] = getTopPlayers(gamesTitle[i]->_text);
            }
            for (int i = 0; i < gamesTitle.size(); i++) {
                int yPos = 435;
                texts = {};
                for (long unsigned int y = 0; (y < _leader[gamesTitle[i]->_text].size() && y < 4); y++) {
                    std::map<std::string, Text*> nameScore;
                    std::string leaderName = std::get<0>(this->_leader[gamesTitle[i]->_text][y]) + "=" + std::to_string(std::get<1>(this->_leader[gamesTitle[i]->_text][y]));
                    Text *text = new Text(leaderName.c_str(), "src/graphicals/sdl2/assets/ARCADE_N.TTF", renderer, green);
                    text->setPos(this->windowSize.getX() / 2 - 180, yPos);
                    yPos += 45;
                    texts.push_back(text);
                }
                _leaderText[gamesTitle[i]->_text] = texts;
            }
        }
        
        void checkGameLibSelected()
        {
            for (int i = 0; i < gamesTitle.size(); i++) {
                if (gamesTitle[i]->_selected)
                    game = gamesTitle[i]->_text;
            }

            for (int i = 0; i < libTitle.size(); i++) {
                if (libTitle[i]->_selected)
                    graph = libTitle[i]->_text;
            }
        }
        
        void handleMenuEvent()
        {
            char result = (this->event.type == SDL_KEYDOWN) ? event.key.keysym.sym : 0;
            delta_time = SDL_GetTicks() - current_time;
            SDL_Color green = {50,205,50};
            SDL_Color white = {255, 255, 255};
            std::vector<Text*> tmp;
            if (allRect[0]->_selected)
                tmp = gamesTitle;
            else
                tmp = libTitle;
            int last = tmp.size() - 1;
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                handleMenuClickEvent();
                return;
            }
            if (delta_time >= delay) {
                switch (result)
                {
                case 82:
                    if (allRect[0]->_selected || allRect[1]->_selected) {
                        setTextToUnselected(tmp);
                        tmp[0]->setPos(tmp[0]->_Message_rect.x, tmp[last]->_Message_rect.y);
                        tmp[0]->setSelected(false, renderer);
                        tmp[1]->setSelected(true, renderer);
                        for (int i = 1; i < tmp.size(); i++) {
                            tmp[i]->setPos(tmp[i]->_Message_rect.x, tmp[i]->_Message_rect.y - 110);
                        }
                        std::rotate(tmp.begin(), tmp.begin()+1, tmp.end());
                        current_time = SDL_GetTicks();
                        checkLeft(tmp);
                    }
                    break;
                case 81:
                    if (allRect[0]->_selected || allRect[1]->_selected) {
                        setTextToUnselected(tmp);
                        tmp[0]->setSelected(false, renderer);
                        tmp[last]->setSelected(true, renderer);
                        tmp[last]->setPos(tmp[last]->_Message_rect.x, 100);
                        for (int i = 0; i < last; i++) {
                            tmp[i]->setPos(tmp[i]->_Message_rect.x, tmp[i]->_Message_rect.y + 110);
                        }
                        std::rotate(tmp.begin(), tmp.begin()+tmp.size()-1, tmp.end());
                        current_time = SDL_GetTicks();
                        checkLeft(tmp);
                    }
                    break;
                case 80:
                    this->allRect[0]->_selected = true;
                    this->allRect[1]->_selected = false;
                    this->PlayButton->setSelected(false, renderer);
                    this->otherText[2]->setSelected(false, renderer);
                    break;
                case 79:
                    this->allRect[0]->_selected = false;
                    this->allRect[1]->_selected = true;
                    this->PlayButton->setSelected(false, renderer);
                    this->otherText[2]->setSelected(false, renderer);
                    break;
                case 13:
                    if (PlayButton->_selected == false) {
                        this->allRect[0]->_selected = false;
                        this->allRect[1]->_selected = false;
                        this->PlayButton->setSelected(true, renderer);
                        this->otherText[2]->setSelected(false, renderer);
                        event.type = SDL_MOUSEBUTTONUP;
                    } else {
                        _play = true;
                    }
                    break;
                default:
                    break;
                }
            }
        }



        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        std::vector<Text*> gamesTitle;
        std::vector<Text*> libTitle;
        std::vector<Text*> otherText;
        std::vector<Rect*> allRect;
        Text *PlayButton;
        Text *Score;
        Vector2i windowSize;
        int event_count = 3;
        unsigned int current_time = 0;
        unsigned int delta_time = 0;
        unsigned int delay = 200;
        bool isMenuInit = false;
        bool isLeft = true;
        bool _play = false;
        std::string namePlayer = "";
        std::map<std::string, std::vector<std::tuple<std::string, int>>> _leader;
        std::map<std::string, std::vector<Text*>> _leaderText;
        std::string game = "pacman";
        std::string graph = "sdl2";
        std::unordered_map<std::string, std::string> playerInfo;
        std::map<std::string, spriteSDL> contentGame;
};

extern "C"
{
    SDL2 lib(1680, 1050);
    
    void entryPoint()
    {
        lib.open();
    }

    IDisplayModule *initDisplay()
    {
        IDisplayModule *SDL = new SDL2(1680, 1050);
        return SDL;
    }

    void displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphs)
    {
        lib.displayMainMenu(games, graphs);
    }

    Vector2i getEventClick()
    {
        Vector2i pos = lib.getEventClick();
        return pos;
    }

    char getKeyboardEvent()
    {
        char character = lib.getKeyboardEvent();
        return character;
    }

    void exitPoint()
    {
        lib.close();
    }

    void forceExitPoint()
    {
        lib.forceExitPoint();
    }

}
