#pragma once

#include "Ghost.hpp"

/**
 * @brief This class represents a ghost Pinky inheriting from the Ghost class
 *
 * @details This class implements the ghost's behaviour
 */

class Pinky : public Ghost{
    public:
        Pinky();
        ~Pinky();
        void tick(const int & tick, const Position & playerPosition);
};