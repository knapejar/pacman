#pragma once

#include <ncurses.h>
#include "ScreenState.hpp"
#include <string>
#include "../Config.hpp"



/**
 * @brief This is the base class for all screens
 * @details This class implements the screen logic state machine used in the main menu
 */

class Screen{
    public:
        Config config;
    protected:
        WINDOW * window;
    public:
        bool running = true;
        Screen();

        /**
         * @brief This method is used to initialize the screen window
         * @details This method is used to initialize the window
         */
        void newWindow(int height, int width, int starty, int startx);

        /**
         * @brief Method used to delete the screen window
         */
        void destroyWindow();

        /**
         * @brief The virtual method used to render the content of the screen
         * @details This method must be implemented by the derived classes
         * @return ScreenState 
         */
        virtual ScreenState show() = 0;
};