#pragma once

#include "Screen.hpp"
#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

using namespace std;

class SelectFileName : public Screen{
    private:
        std::string path;
        std::string chosenFileName;
        std::vector<std::string> content;
    public:
        SelectFileName();
        SelectFileName(std::string path);
        void load();
        ScreenState show();
        std::string getChosenFileName();
};