#pragma once

#include "Field.hpp"
#include "../entity/Position.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/**
 * @brief This class represents the game map, stores the spawning positions of the entities, parses the map from a file
 *
 * @details This class uses the Field class to store the map data
 * @details It is responsible for the map parsing
 * @details Description of the map file format:
 * @details - First line: width, height
 * @details - Following lines: map data
 * @details - Map data:
 * @details - '.': dot
 * @details - '_': empty field
 * @details - '#': wall
 * @details - 'P': player spawn
 * @details - 'B': Blinky spawn
 * @details - 'C': Clyde spawn
 * @details - 'I': Inky spawn
 * @details - 'G': Pinky spawn
 * @details - 'o': healing cherry spawn
 * @details - '*': healing bonus spawn
 * @details - Last line: delay between ghost spawn in game ticks
 */

class Map{
    private:
        std::vector<std::vector<Field>> map;
        int width;
        int height;
        int scoreTarget;
        int ghostReleaseTimeout = 60;

    public:
        /**
         * @brief Constructor with the default map - makes the game playable even without any map files
        */
        Map();

        /**
         * @brief Construct a new Map object from a map file
         * 
         * @param fileName 
         */
        Map(std::string fileName);

        /**
         * @brief Destroy the Map object
         * 
         */
        ~Map();

        /**
         * @brief Set the Field object
         * 
         * @param position 
         * @param field 
         */
        void setField(Position position, Field field);

        /**
         * @brief Get the Field object
         * 
         * @param position 
         * @return Field 
         */
        Field getField(Position position);
        
        /**
         * @brief Get the width of the map
         * 
         * @return int 
         */
        int getWidth();

        /**
         * @brief Get the height of the map
         * 
         * @return int 
         */
        int getHeight();

        /**
         * @brief Get the Ghost Release Timeout object
         * 
         * @return int 
         */
        int getGhostReleaseTimeout();

        /**
         * @brief Renders the map to the ostream
         * 
         * @param os 
         * @return std::ostream& 
         */
        std::ostream & render(std::ostream & os);

        /**
         * @brief Returns if the field is a wall
         * 
         * @param position
         */
        bool wall(Position position);

        /**
         * @brief Returns if the field is a point
         * 
         * @param position
         */
        bool point(Position position);

        /**
         * @brief Returns if the field is a spawn point of a ghost
         * 
         * @param position
         */
        bool ghost(Position position);

        /**
         * @brief Returns if the field is a spawn point of a player
         * 
         * @param position
         */
        bool pacman(Position position);

        /**
         * @brief Returns the score target of the map
         * 
         */
        void calculateScoreTarget();

        /**
         * @brief Get the Total Score object
         * 
         * @return int 
         */
        int getTotalScore();

        /**
         * @brief Collects the point from the given position - used by the Player class
         * 
         * @param position 
         * @return true if there was a point
         * @return false if there was no point
         */
        bool collect(Position position);

        /**
         * @brief Picks up the cherry bonus from the given position - used by the Player class
         * 
         * @param position 
         * @return true if there was a cherry bonus
         * @return false if there was no cherry bonus
         */
        bool pickUpCherry(Position position);

        /**
         * @brief Picks up the bonus from the given position - used by the Player class
         * 
         * @param position 
         * @return true if there was a bonus
         * @return false if there was no bonus
         */
        bool pickUpBonus(Position position);
};