#include "Nibbler.hpp"

extern "C" {
    
    arcade::IGameModule *initGame(void)
    {
        arcade::IGameModule *nibbler = new Nibbler();
        return nibbler;
    }
}
