#pragma once

#include <ncurses.h>

#include "Angle.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Inky.hpp"
#include "Pinky.hpp"
#include "../map/Map.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <climits>


/**
 * @brief class that is responsible for managing all the entities in the game implementing Player, Ghost, Blinky, Clyde, Inky, Pinky
 * @details It is responsible for creating, updating and rendering all the entities in the game.
 * @details This class is implemented by the Game class.
 */

class EntityManager{
    private:
        /**
         * @brief The map pointer used to acces the map to avoid colissions
         */
        Map * map = nullptr;

        /**
         * @brief The window pointer used to render the map
         */
        WINDOW * window = nullptr;

        size_t totalTicks = 0;
        size_t ghostsReleased = 0;
        int ghostsEatable = 0;

    public:
        Player player;
        std::vector<std::shared_ptr<Ghost>> ghosts;
        
        /**
         * @brief Construct a new Entity Manager object - used by Game
         * 
         */
        EntityManager();

        /**
         * @brief Imports the map and sets the player and ghosts
         * @param map The map to import
         * @return The EntityManager
         */
        EntityManager importMap(Map * map);

        /**
         * @brief Imports the window
         * @param window The window to import
         * @return The EntityManager
         */
        EntityManager importWindow(WINDOW * window);

        /**
         * @brief Renders the player and ghosts
         * @return The EntityManager
         */
        EntityManager render();

        /**
         * @brief Renders the player and ghosts
         * @return The EntityManager
         */
        EntityManager renderHalf();
        
        /**
         * @brief Hides the player and ghosts in order to re-render them in the next tick
         * @return The EntityManager
         */
        EntityManager hide();

        /**
         * @brief Updates the player and ghosts
         * @return The EntityManager
         */
        EntityManager tick();

        /**
         * @brief Returns the total ticks
         * @return The total ticks
         */
        bool gameEnded();
};