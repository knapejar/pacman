#pragma once

#include "Screen.hpp"
#include <ncurses.h>

using namespace std;

class Menu : public Screen{
    public:
        Menu();
        ScreenState show();
};