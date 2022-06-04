#pragma once

#include <ncurses.h>

#include "Angle.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include "Blinky.hpp"
#include "Clyde.hpp"
//include "ghosts/Inky.hpp"
//#include "ghosts/Pinky.hpp"
#include "../map/Map.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>



class EntityManager{
    private:
        Map * map;
        WINDOW * window;

    public:
        Player player;
        vector<shared_ptr<Ghost>> ghosts;
        
        EntityManager();
        ~EntityManager();
        EntityManager importMap(Map * map);
        EntityManager importWindow(WINDOW * window);

        EntityManager render();
        EntityManager renderHalf();
        EntityManager hide();
        EntityManager tick();
};