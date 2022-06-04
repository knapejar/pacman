#pragma once

#include "Entity.hpp"

class Ghost : public Entity{
        vector<Angle> path; 
    public:
        Ghost();
        Ghost(Position position, Angle angle);
        ~Ghost();
        virtual void calculatePath() = 0;
        virtual void tick(int tick) = 0;
};