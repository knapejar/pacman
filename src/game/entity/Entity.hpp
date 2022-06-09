#pragma once

#include <ncurses.h>

#include "../map/Map.hpp"

#include "../../Config.hpp"

#include "Angle.hpp"
#include "Position.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>



/**
 * @brief This is the base class for all entities including the Player and the Ghost classes
 * 
 * @details This class is being implemented by the EntityManager class and is responsible for the entity logic and rendering
 * @details Configuration of the renderer can be done in the Config class
 */

class Entity{
    public:
        Config config;
    protected:
        Position position; //Entity position is being calculated *2 in order to smooth the animation
        Position lastPosition;
        Position spawnPosition;
        Angle angle;
        bool isAlive = true;
        std::string name = "Entity";
        std::string saveName = "?";
        std::string renderName = config.entityRenderBox;
        std::string renderNameLower = config.entityRenderBoxLower;
        std::string renderNameUpper = config.entityRenderBoxUpper;
        Map * map;
    public:
        int color = 1; //WHITE
        Entity();
        Entity(Position position, Angle angle);
        ~Entity();

        /**
         * @brief This method imports the map data from the Map class
         * 
         * @param map 
         * @return Entity 
         */
        Entity importMap(Map * map);

        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName() const;

        /**
         * @brief Get the Position object
         * 
         * @return Position 
         */
        Position getPosition() const;

        /**
         * @brief Set the Position object
         * 
         * @param position 
         * @return Entity 
         */
        Entity setPosition(Position position);

        /**
         * @brief Get the Angle object
         * 
         * @return Angle 
         */
        Angle getAngle() const;

        /**
         * @brief Set the Angle object
         * 
         * @param angle 
         * @return Entity 
         */
        Entity setAngle(Angle angle);

        /**
         * @brief Move the entity back in the bounds of the map
         * 
         * @param position - the desired position to repair
         * @return bool 
         */
        void teleportCheck();
        void teleportCheck(Position & position);

        /**
         * @brief Performs one tick of the entity logic
         * 
         * @return Entity 
         */
        Entity tick();

        /**
         * @brief Hides the entity
         * 
         * @param window 
         * @return Entity 
         */
        Entity hide(WINDOW * window);

        /**
         * @brief Renders the entity
         * 
         * @param window 
         * @return Entity 
         */
        Entity render(WINDOW * window);

        /**
         * @brief Renders the entity between two ticks to make the smooth animation
         * 
         * @param window 
         * @return Entity 
         */
        Entity renderHalf(WINDOW * window);

        /**
         * @brief Respawns the entity at the spawn position
         * 
         */
        void respawn();
};