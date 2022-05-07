#pragma once

#include "Angle.hpp"

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
};