#pragma once

#include <string>

class Config{
    public:
        std::string mapsFolder = "examples/";
        std::string about = "PACMAN\n \nHow to play:\nUse the arrow keys to move the pacman.\nChoose PLAY to start the game.\nChoose EXIT to exit the game.";
        std::string mapErrorMsg = "Error loading map:";
};