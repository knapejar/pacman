#pragma once

#include "Ghost.hpp"

class Pinky : public Ghost{
    public:
        Pinky();
        ~Pinky();
        void calculatePath();
        void tick(int tick);
};