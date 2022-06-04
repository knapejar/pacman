#pragma once

#include <ncurses.h>

#include "map/Map.hpp"
#include "entity/Angle.hpp"

#include "entity/EntityManager.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>



class Game{
    private:
        Map map;
        EntityManager entityManager;
        
        int tickLength = 100;
        WINDOW * window;
    public:
        Game();
        Game(string fileName);
        ~Game();
        void run();
    
};