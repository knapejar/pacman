#include "Entity.hpp"

Entity::Entity(){

}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->angle = angle;
}

Entity::~Entity(){

}
Entity Entity::setAngle(Angle angle){
    this->angle = angle;
    return *this;
}

Entity Entity::tick(){
    Position next = this->position.move(this->angle, 1);
    //TODO
    this->position = next;
    return *this;
}

