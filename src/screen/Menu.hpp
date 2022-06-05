#pragma once

#include "Screen.hpp"
#include <ncurses.h>
#include <string.h>



/**
 * @brief Class responsible for the main menu rendering and navigation
 * @details This class implements the screen logic state machine used in the main menu - enum ScreenState
 */

class Menu : public Screen{
    public:
        Menu();

        /**
         * @brief Method to create a new menu window
         * 
         * @return ScreenState - the next screen state
         */
        ScreenState show();
};