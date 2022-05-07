#pragma once

#include <ncurses.h>

#include "map/Map.hpp"
#include "entity/Angle.hpp"
#include "entity/Player.hpp"
#include "entity/Ghost.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Game{
    private:
        Map map;
        Player player;
        vector<Ghost> ghosts;
    public:
        Game();
        Game(string fileName);
        ~Game();
        void run();

    
};