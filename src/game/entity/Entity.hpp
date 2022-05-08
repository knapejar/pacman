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
        Position position;
        Position lastPosition;
        Angle angle;
        bool isAlive = true;
        string name = "Entity";
        string saveName = "?";
        string renderName = "██";
        string renderNameLower = "▄▄";
        string renderNameUpper = "▀▀";
        int color = COLOR_WHITE;
        Map * map;
    public:
        Entity();
        Entity(Position position, Angle angle);
        ~Entity();
        Entity importMap(Map * map);
        Position getPosition();
        Entity setPosition(Position position);
        Angle getAngle();
        Entity setAngle(Angle angle);
        Entity tick();
        Entity hide(WINDOW *window);
        Entity render(WINDOW *window);
        Entity renderHalf(WINDOW *window);
};