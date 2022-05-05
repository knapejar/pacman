#pragma once

#include "Screen.hpp"
#include <ncurses.h>

using namespace std;

class SelectFileName : public Screen{
    public:
        ScreenState show(string FileName);
};