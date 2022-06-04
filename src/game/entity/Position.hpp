#pragma once

#include "Angle.hpp"
#include <math.h>

/**
 * @brief The Position class
 * @details This class is used to store the position of an entity.
 * @var x The x coordinate of the entity.
 * @var y The y coordinate of the entity.
 */

class Position {
    private:
        int x;
        int y;
    public:
        Position();
        Position(int x, int y);
        ~Position();
        int getX();
        int getY();
        Position setX(int x);
        Position setY(int y);
        Position setXY(int x, int y);
        Position move(int x, int y);
        Position move(Position position);
        Position move(Angle angle, int distance);
        Position operator+(Position position);
        Position operator-(Position position);
        bool operator==(Position position);
        bool operator!=(Position position);
        int distance(Position position);
};