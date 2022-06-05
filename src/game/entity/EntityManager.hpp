#pragma once

#include <ncurses.h>

#include "Angle.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Inky.hpp"
#include "Pinky.hpp"
#include "../map/Map.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <climits>



class EntityManager{
    private:
        Map * map;
        WINDOW * window;
        size_t totalTicks = 0;
        size_t ghostsReleased = 0;

    public:
        Player player;
        std::vector<std::shared_ptr<Ghost>> ghosts;
        
        EntityManager();
        ~EntityManager();
        EntityManager importMap(Map * map);
        EntityManager importWindow(WINDOW * window);

        EntityManager render();
        EntityManager renderHalf();
        EntityManager hide();
        EntityManager tick();

        bool gameEnded();
};