#pragma once

#include <ncurses.h>

#include "../map/Map.hpp"

#include "Angle.hpp"
#include "Position.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
        

class Entity{
    protected:
        Position position; //Entity position is being calculated *2 in order to smooth the animation
        Position lastPosition;
        Angle angle;
        bool isAlive = true;
        string name = "Entity";
        string saveName = "?";
        string renderName = "██";
        string renderNameLower = "▄▄";
        string renderNameUpper = "▀▀";
        int color = 1; //WHITE
        Map * map;
        Map * entityMap;
    public:
        Entity();
        Entity(Position position, Angle angle);
        ~Entity();
        Entity importMaps(Map * map, Map * entityMap);
        Position getPosition();
        Entity setPosition(Position position);
        Angle getAngle();
        Entity setAngle(Angle angle);
        Entity tick();
        Entity hide(WINDOW *window);
        Entity render(WINDOW *window);
        Entity renderHalf(WINDOW *window);
};