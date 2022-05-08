#include "Map.hpp"

Map::Map(){
    //Declare initial map 
    width = 17;
    height = 19;
    fieldType n = NONE;
    fieldType p = POINT;
    fieldType s = PACMAN;
    fieldType g = GHOST;
    fieldType w = WALL;
    map = { {Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w)},
            {Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(s),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(n),Field(n)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(g),Field(g),Field(g),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p)},
            {Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w),Field(w),Field(w),Field(p),Field(w),Field(p),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(w),Field(p),Field(w),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(p),Field(w),Field(p),Field(w),Field(n),Field(n)},
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