#pragma once

#include <string>

class Config{
    public:
        
        std::string entityRenderBox = "██";
        std::string entityRenderBoxLower = "▄▄";
        std::string entityRenderBoxUpper = "▀▀";

        std::string mapsFolder = "examples/";
        std::string about = "HOW TO PLAY\n \nPacman is the yellow dot :)\nUse the arrow keys to move the pacman.\nCollect the pick-ups to heal.\nAvoid the ghosts - coloured dots.\nCollect all of the dots in the level to win!\n \n";
        std::string mapErrorMsg = "Error loading map:";
};