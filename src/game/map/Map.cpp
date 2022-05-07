#include "Map.hpp"

Map::Map(){
    //Declare initial map 
    width = 20;
    height = 15;
}

Map::~Map(){

}

void Map::setField(int x, int y, Field field){

}
Field Map::getField(int x, int y){
    return Field();
}

int Map::getWidth(){
    return this->width;
}

int Map::getHeight(){
    return this->height;
}