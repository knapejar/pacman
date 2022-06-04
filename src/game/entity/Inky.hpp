#pragma once

#include "Ghost.hpp"

class Inky : public Ghost{
    public:
        Inky();
        ~Inky();
        void calculatePath();
        void tick(int tick);
};