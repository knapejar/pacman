#pragma once

#include "Screen.hpp"
#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>


/**
 * @brief Use it to display overlay text on the screen
 * 
 * @details Used to display HowTo screen, game results and exceptions during loading the map
 */

class TextScreen : public Screen{
    private:
        std::vector<std::string> content;
    public:
        TextScreen();
        TextScreen(std::string content);

        /**
         * @brief Shows the user the content of the text screen
         * 
         * @return ScreenState 
         */
        ScreenState show();
};