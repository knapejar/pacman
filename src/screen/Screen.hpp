#pragma once

#include <ncurses.h>
#include "ScreenState.hpp"
#include <string>

using namespace std;

class Screen{
    protected:
        WINDOW * window;
    public:
        bool running = true;
        Screen();
        void newWindow(int height, int width, int starty, int startx);
        void destroyWindow();
        virtual ScreenState show() = 0;
};