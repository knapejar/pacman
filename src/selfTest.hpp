#pragma once

#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <climits>
#include <assert.h>

#include "game/Game.hpp"



class SelfTest{
    private:
        bool verbose = false;
    public:
        SelfTest();
        SelfTest(bool verbose);
        ~SelfTest();
        bool test();
};
