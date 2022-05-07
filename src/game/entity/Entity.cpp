#include "Entity.hpp"

Entity::Entity(){

}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->angle = angle;
}

Entity::~Entity(){

}
Position Entity::getPosition(){
    return this->position;
}
Entity Entity::setPosition(Position position){
    this->position = position;
    return *this;
}
Angle Entity::getAngle(){
    return this->angle;
}
Entity Entity::setAngle(Angle angle){
    this->angle = angle;
    return *this;
}

Entity Entity::tick(){
    this->position = this->position.move(this->angle, 1);
    return *this;
}

