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
        Map();
        Map(std::string fileName);
        ~Map();
        void setField(Position position, Field field);
        Field getField(Position position);
        int getWidth();
        int getHeight();
        int getGhostReleaseTimeout();
        std::ostream & render(std::ostream & os);
        bool wall(Position position);
        bool point(Position position);
        bool ghost(Position position);
        bool pacman(Position position);
        void calculateScoreTarget();
        int getTotalScore();
        bool collect(Position position);
        bool pickUpCherry(Position position);
        bool pickUpBonus(Position position);
};