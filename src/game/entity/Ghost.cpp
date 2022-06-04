#include "Ghost.hpp"

Ghost::Ghost(): Entity(){
    this->name = "Ghost";
    this->color = 3;
}
Ghost::Ghost(Position position, Angle angle):Entity(position, angle){
    this->name = "Ghost";
}
Ghost::~Ghost(){

}