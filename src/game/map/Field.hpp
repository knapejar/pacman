#pragma once

#include <iostream>
#include <fstream>

using namespace std;

enum fieldType {
    NONE,
    WALL,
    POINT,
    PACMAN,
    GHOST,
    BLINKY,
    CLYDE,
    INKY,
    PINKY
};

class Field {
    private:
        enum fieldType field;

    public:
        Field();
        Field(fieldType field);
        ~Field();
        Field getField();
        void setFieldType(fieldType field);
        istream & load(istream & is);
        ostream & save(ostream & os);
        ostream & render(ostream & os);
        bool wall();
        bool point();
        char toChar();
};