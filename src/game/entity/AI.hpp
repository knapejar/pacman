#pragma once

#include <vector>
#include <string>
#include "../map/Map.hpp"
#include "Angle.hpp"
#include "Position.hpp"
#include "Entity.hpp"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <climits>

#include "../../screen/TextScreen.hpp"



/**
 * @brief Position node used by the depth first search algorithm
 */

struct Node{
    Position position;
    int distance;
    bool operator>(const Node& a) const{
        return this->distance > a.distance;
    }
};

/**
 * @brief class that is responsible for pathfinding the ghosts
 */

class AI{
    public:
        /**
         * @brief Constructs a new std::vector<Angle>calculate Path containing the closest path to the desired location
         * 
         * @param map 
         * @param start - the start position
         * @param end - the end position
         */
        std::vector<Angle>calculatePath(Map * map, const Position & start, const Position & end);

        /**
         * @brief Chooses a random spot on the map, which is not a wall
         * 
         * @param map
         * @return Position 
         */
        Position randomPosition(Map * map);

        /**
         * @brief Chooses a random spot on the map, which is not a wall or nearby the player
         * 
         * @param map 
         * @param playerPosition 
         * @return Position 
         */
        Position awayFromPlayer(Map * map, const Position & playerPosition);
};