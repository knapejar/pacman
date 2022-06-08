#pragma once

#include <iostream>
#include <fstream>



/**
 * @brief All possible field types in the map
 * @details further information about the enum values can ve foung in the Map class description
 */

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



/**
 * @brief This class is being used to store the map data by the Map class
 * 
 * @details It is responsible for parsing each field from the map file stream
 */

class Field {
    private:
        enum fieldType field;

    public:
        Field();
        Field(fieldType field);
        ~Field();
        Field getField() const;
        void setFieldType(fieldType field);
        std::istream & load(std::istream & is);
        std::ostream & save(std::ostream & os);
        std::ostream & render(std::ostream & os);
        bool wall() const;
        bool point() const;
        bool ghost() const;
        bool pacman() const;
        char toChar() const;
};