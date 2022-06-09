#pragma once

#include "Ghost.hpp"

/**
 * @brief This class represents a ghost Clyde inheriting from the Ghost class
 *
 * @details This class implements the ghost's behaviour
 */

class Clyde : public Ghost{
    public:
        Clyde();
        ~Clyde();
        void tick(const int & tick, const Position & playerPosition);
};