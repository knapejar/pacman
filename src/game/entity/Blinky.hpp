#pragma once

#include "Ghost.hpp"

/**
 * @brief This class represents a ghost Blinky inheriting from the Ghost class
 *
 * @details This class implements the ghost's behaviour
 */

class Blinky : public Ghost{
    public:
        Blinky();
        ~Blinky();
        void calculatePath();
        void tick(int tick);
};