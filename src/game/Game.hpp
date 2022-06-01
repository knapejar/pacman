#pragma once

#include <ncurses.h>

#include "map/Map.hpp"
#include "entity/Angle.hpp"
#include "entity/Player.hpp"
#include "entity/Ghost.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Game{
    private:
        Map map;
        Map entityMap;
        Player player;
        vector<Ghost> ghosts;
        int tickLength = 100;
        WINDOW * window;
    public:
        Game();
        Game(string fileName);
        ~Game();
        void run();
        void renderAll();
        void renderHalfAll();
        void hideAll();
        void tickAll();

    
};