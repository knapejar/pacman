#pragma once

#include "Screen.hpp"
#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TextScreen : public Screen{
    private:
        std::vector<std::string> content;
    public:
        TextScreen();
        TextScreen(std::string content);
        ScreenState show();
};