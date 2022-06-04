#pragma once

#include "Field.hpp"
#include "../entity/Position.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Map{
    private:
        vector<vector<Field>> map;
        int width;
        int height;
        int scoreTarget;

    public:
        Map();
        ~Map();
        void setField(Position position, Field field);
        Field getField(Position position);
        int getWidth();
        int getHeight();
        ostream & render(ostream & os);
        bool wall(Position position);
        bool point(Position position);
        void calculateScoreTarget();
        int getTotalScore();
        bool collect(Position position);
};