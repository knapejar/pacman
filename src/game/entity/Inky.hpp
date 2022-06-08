#pragma once

#include "Ghost.hpp"

/**
 * @brief This class represents a ghost Inky inheriting from the Ghost class
 *
 * @details This class implements the ghost's behaviour
 */

class Inky : public Ghost{
    public:
        Inky();
        ~Inky();
        void tick(int tick, Position playerPosition);
};