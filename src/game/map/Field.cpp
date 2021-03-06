#include "Field.hpp"

using namespace std;



Field::Field(){
    this->field = NONE;
}

Field::Field(fieldType field){
    this->field = field;
}

Field::~Field(){
    
}

Field Field::getField() const{
    return Field();
}

void Field::setFieldType(fieldType field){
    this->field = field;
}

istream & Field::load(istream & is){
    char c;
    is >> c;
    switch (c){
        case '_':
            this->field = NONE;
            break;
        case '#':
            this->field = WALL;
            break;
        case '.':
            this->field = POINT;
            break;
        case 'o':
            this->field = CHERRY;
            break;
        case '*':
            this->field = BONUS;
            break;
        case 'P':
            this->field = PACMAN;
            break;
        case 'B':
            this->field = BLINKY;
            break;
        case 'C':
            this->field = CLYDE;
            break;
        case 'I':
            this->field = INKY;
            break;
        case 'G':
            this->field = PINKY;
            break;
        default:
            throw std::runtime_error("Field::load: Unknown field type");
            break;
    }
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
        case BLINKY:
        case CLYDE:
        case INKY:
        case PINKY:
            os << "  ";
            break;
        case WALL:
            os << "██";
            break;
        case POINT:
            os << "<>";
            break;
        case CHERRY:
            os << "oO";
            break;
        case BONUS:
            os << "<3";
            break;
    }
    return os;
}

bool Field::wall() const{
    return field == WALL;
}
bool Field::point() const{
    return field == POINT;
}
bool Field::ghost() const{
    return field == GHOST || field == BLINKY || field == CLYDE || field == INKY || field == PINKY;
}
bool Field::pacman() const{
    return field == PACMAN;
}
char Field::toChar() const{
    switch (field){
        case NONE:
            return ' ';
        case WALL:
            return '#';
        case POINT:
            return '.';
        case CHERRY:
            return 'o';
        case BONUS:
            return '*';
        case PACMAN:
            return 'P';
        case GHOST:
            return ' ';
        case BLINKY:
            return 'B';
        case CLYDE:
            return 'C';
        case INKY:
            return 'I';
        case PINKY:
            return 'G';
        default:
            return ' ';
    }
}