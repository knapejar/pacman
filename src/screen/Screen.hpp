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
        void newWindow(int height, int width, int starty, int startx);
        void destroyWindow();
        virtual ScreenState show() = 0;
};