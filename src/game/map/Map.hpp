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

    public:
        Map();
        ~Map();
        void setField(int x, int y, Field field);
        Field getField(int x, int y);
        int getWidth();
        int getHeight();
        ostream & render(ostream & os);
        bool wall(Position position);
};