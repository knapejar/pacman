#include "Map.hpp"

Map::Map(){
    //Declare initial map 
    width = 17;
    height = 19;
    fieldType n = NONE;
    fieldType p = POINT;
    fieldType s = PACMAN;
    fieldType a = BLINKY;
    fieldType b = CLYDE;
    fieldType c = INKY;
    fieldType d = PINKY;
    fieldType w = WALL;
    map = { {Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(n),Field(n)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(a),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(b),Field(c),Field(d),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(s),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(n),Field(n)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w)}
        };
    calculateScoreTarget();
}

Map::Map(std::string filename){
    ifstream file(filename);
    if (!file.is_open()){
        throw std::runtime_error("Could not open file");
    }
    //First line is width and height
    file >> width;
    file >> height;
    //Check for valid width and height
    if (width < 9 || height < 9 || file.fail()){
        throw std::runtime_error("Invalid width or height - minimum is w:9, h:9");
    }
    //Load map
    map.resize(height);
    for (int i = 0; i < height; i++){
        map[i].resize(width);
        for (int j = 0; j < width; j++){
            map[i][j].load(file);
            if (file.fail()){
                throw std::runtime_error("Invalid map");
            }
        }
    }
    calculateScoreTarget();
}

Map::~Map(){

}

Field Map::getField(Position position){
    return map[position.getY()][position.getX()];
}

int Map::getWidth(){
    return this->width;
}

int Map::getHeight(){
    return this->height;
}

ostream & Map::render(ostream & os){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            map[i][j].render(os);
        }
    }
    return os;
}

bool Map::wall(Position position){
    return map[position.getY()][position.getX()].wall();
}
bool Map::point(Position position){
    return map[position.getY()][position.getX()].point();
}

void Map::calculateScoreTarget(){
    scoreTarget = 0;
    for (auto line : map){
        for (auto field : line){
            if (field.point()){
                scoreTarget += 1;
            }
        }
    }
}

int Map::getTotalScore(){
    return this->scoreTarget;
}

bool Map::collect(Position position){
    if (this->map[position.getY()][position.getX()].point()){
        this->map[position.getY()][position.getX()] = NONE;
        return true;
    }
    return false;
}
bool Map::pickUpCherry(Position position){
    if (this->map[position.getY()][position.getX()].toChar() == 'o'){
        this->map[position.getY()][position.getX()] = NONE;
        return true;
    }
    return false;
}
bool Map::pickUpBonus(Position position){
    if (this->map[position.getY()][position.getX()].toChar() == '*'){
        this->map[position.getY()][position.getX()] = NONE;
        return true;
    }
    return false;
}