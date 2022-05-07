#include "Entity.hpp"

Entity::Entity(){

}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->angle = angle;
}

Entity::~Entity(){

}

Entity Entity::tick(){
    return *this;
}

