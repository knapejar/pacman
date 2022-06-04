#pragma once

#include "Ghost.hpp"

class Clyde : public Ghost{
    protected:
        int color = 4;
    public:
        Clyde();
        ~Clyde();
        void calculatePath();
};