#pragma once

#include <iostream>
#include <fstream>



enum fieldType {
    NONE,
    WALL,
    POINT,
    CHERRY,
    BONUS,
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
        std::istream & load(std::istream & is);
        std::ostream & save(std::ostream & os);
        std::ostream & render(std::ostream & os);
        bool wall();
        bool point();
        bool ghost();
        bool pacman();
        char toChar();
};