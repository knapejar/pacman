#pragma once

#include "Ghost.hpp"

class Clyde : public Ghost{
    public:
        Clyde();
        ~Clyde();
        void calculatePath();
        void tick(int tick);
};