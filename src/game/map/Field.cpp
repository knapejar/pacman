#include "Field.hpp"

Field::Field(){
    this->field = NONE;
}

Field::~Field(){
    
}

Field Field::getField(){
    return Field();
}

void Field::setField(fieldType field){
    this->field = field;
}

istream & Field::load(istream & is){
    //TODO apply the dictionary there
    return is;
}

ostream & Field::save(ostream & os){
    //TODO dictionary
    return os;
}

ostream & Field::render(ostream & os){
    switch (field){
        case NONE:
        case PACMAN:
        case GHOST:
            os << "  ";
            break;
        case WALL:
            os << "[]";
            break;
        case POINT:
            os << "()";
            break;
    }
    return os;
}