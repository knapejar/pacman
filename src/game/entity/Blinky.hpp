#pragma once

#include "Ghost.hpp"

class Blinky : public Ghost{
    public:
        Blinky();
        ~Blinky();
        void calculatePath();
        void tick(int tick);
};