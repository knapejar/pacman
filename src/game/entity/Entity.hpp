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
    public:
        Entity();
        ~Entity();
        pair<int,int> getPos();

    
};