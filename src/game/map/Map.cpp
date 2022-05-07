#include "Map.hpp"

Map::Map(){
    //Declare initial map 
    width = 17;
    height = 19;
    fieldType n = NONE;
    fieldType w = WALL;
    map = { {Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w)},
            {Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w)},
            {Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w)},
            {Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w)},
            {Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w)},
            {Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(w),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w)},
            {Field(w),Field(w),Field(w),Field(n),Field(w),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(w),Field(n),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(w),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(w),Field(n),Field(n)},
            {Field(w),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(n),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n)},
            {Field(w),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(w)},
            {Field(n),Field(n),Field(w),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(w),Field(n),Field(n)},
            {Field(w),Field(w),Field(w),Field(n),Field(w),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(w),Field(n),Field(w),Field(w),Field(w)},
            {Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(w),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w)},
            {Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w)},
            {Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w)},
            {Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w),Field(w),Field(n),Field(w)},
            {Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(n),Field(w)},
            {Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w),Field(w)}
        };
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

ostream & Map::render(ostream & os){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            map[i][j].render(os);
        }
    }
    return os;
}