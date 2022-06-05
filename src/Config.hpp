#pragma once

#include <string>



/**
 * @brief This is the configuration class for the game, containing rendering options and game options
 *
 * @details You can set following options:
 * @details - entity rendering character
 * @details - maps folder
 * @details - Longer messages and error messages
 */

class Config{
    public:
        int tickLength = 100; // One tick length in ms
        int playerHealth = 3; // Player health at the beginning of the game
        bool performSelfTest = true;
        bool selfTestVerbose = false;

        std::string entityRenderBox = "██";
        std::string entityRenderBoxLower = "▄▄";
        std::string entityRenderBoxUpper = "▀▀";

        std::string mapsFolder = "examples/";

        std::string menuHeadline = "PACMAN";
        std::string menuSplitter = "──────────";
        std::string menuCopyright = "(c) KNAPEJAR";
        std::string menuFit = "FIT CVUT 2022";

        std::string about = "HOW TO PLAY\n \nPacman is the yellow dot :)\nUse the arrow keys to move the pacman.\nCollect the pick-ups to heal.\nAvoid the ghosts - coloured dots.\nCollect all of the dots in the level to win!\n \n";
        std::string folderErrorMsg = "\nPlease create the folder Examples,\nyou can store your maps there.\n \n";
        std::string mapErrorMsg = "Error loading map:";
};