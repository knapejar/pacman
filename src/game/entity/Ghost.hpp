#pragma once

#include "Entity.hpp"

class Ghost : public Entity{
    private:
        string name = "Ghost";
        string saveName = "G";
        string renderName = "GG";
    public:
        Ghost();
        Ghost(Position position, Angle angle);
        ~Ghost();
};