#pragma once

#include "Screen.hpp"
#include <ncurses.h>

using namespace std;

class Menu : public Screen{
    public:
        ScreenState show();
};