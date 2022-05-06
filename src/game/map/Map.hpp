#pragma once

#include "Field.hpp"

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
        Map(int width, int height);
        void setField(int x, int y, Field field);
        Field getField(int x, int y);
        int getWidth();
        int getHeight();
};