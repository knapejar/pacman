#pragma once

#include "Field.hpp"
#include "../entity/Position.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>



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