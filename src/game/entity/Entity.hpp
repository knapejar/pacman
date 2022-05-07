#pragma once

#include "Angle.hpp"
#include "Position.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
        

class Entity{
    private:
        Position position;
        Angle angle;
        bool isAlive = true;
        string name;
        string saveName = "?";
        string renderName = "<>";
    public:
        Entity();
        Entity(Position position, Angle angle);
        ~Entity();
        Position getPosition();
        Entity setPosition(Position position);
        Angle getAngle();
        Entity setAngle(Angle angle);
        Entity tick();
};