#pragma once

#include <ncurses.h>

#include "../map/Map.hpp"

#include "Angle.hpp"
#include "Position.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>



class Entity{
    protected:
        Position position; //Entity position is being calculated *2 in order to smooth the animation
        Position lastPosition;
        Position spawnPosition;
        Angle angle;
        bool isAlive = true;
        std::string name = "Entity";
        std::string saveName = "?";
        std::string renderName = "██";
        std::string renderNameLower = "▄▄";
        std::string renderNameUpper = "▀▀";
        Map * map;
    public:
        int color = 1; //WHITE
        Entity();
        Entity(Position position, Angle angle);
        ~Entity();
        Entity importMap(Map * map);
        std::string getName();
        Position getPosition();
        Entity setPosition(Position position);
        Angle getAngle();
        Entity setAngle(Angle angle);
        void teleportCheck();
        void teleportCheck(Position & position);
        Entity tick();
        Entity hide(WINDOW *window);
        Entity render(WINDOW *window);
        Entity renderHalf(WINDOW *window);
        void respawn();
};