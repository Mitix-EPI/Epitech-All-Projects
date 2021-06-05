#include "pacman.hpp"

extern "C" {
    
    arcade::IGameModule *initGame(void)
    {
        arcade::IGameModule *pacman = new Pacman();
        return pacman;
    }
}
