#include "Entity.hpp"

using namespace std;
        

        
Entity::Entity(){
    this->position = Position(0, 0);
    this->lastPosition = this->position;
    this->spawnPosition = this->position;
    this->angle = Angle(0);
    this->isAlive = true;
    this->map = NULL;
}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->lastPosition = this->position;
    this->spawnPosition = this->position;
    this->angle = angle;
    this->isAlive = true;
    this->map = NULL;
}

Entity::~Entity(){

}

Entity Entity::importMap(Map * map){
    this->map = map;
    return *this;
}
string Entity::getName(){
    return this->name;
}
Position Entity::getPosition(){
    return this->position;
}
Entity Entity::setPosition(Position position){
    this->position = position;
    this->lastPosition = this->position;
    this->spawnPosition = this->position;
    return *this;
}
Angle Entity::getAngle(){
    return this->angle;
}
Entity Entity::setAngle(Angle angle){
    this->angle = angle;
    return *this;
}

Entity Entity::hide(WINDOW *window){
    if (window == nullptr)
        return *this;
    wattron(window, COLOR_PAIR(1));
    ostringstream ss;
    map->getField(this->position).render(ss);
    mvwprintw(window, position.getY(), position.getX()*2, ss.str().c_str());
    ss.str("");
    map->getField(this->lastPosition).render(ss);
    mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, ss.str().c_str());
    return *this;
}

Entity Entity::render(WINDOW *window){
    if (window == nullptr)
        return *this;
    wattron(window, COLOR_PAIR(color));
    mvwprintw(window, position.getY(), position.getX()*2, renderName.c_str());
    return *this;
}

Entity Entity::renderHalf(WINDOW *window){
    if (window == nullptr)
        return *this;
    if (position == lastPosition){
        render(window);
        return *this;
    }
    wattron(window, COLOR_PAIR(color));
    if (position.getX() == lastPosition.getX() and position.getY() < lastPosition.getY()){
        mvwprintw(window, position.getY(), position.getX()*2, renderNameLower.c_str());
        mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, renderNameUpper.c_str());
    } else if (position.getX() == lastPosition.getX() and position.getY() > lastPosition.getY()){
        mvwprintw(window, position.getY(), position.getX()*2, renderNameUpper.c_str());
        mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, renderNameLower.c_str());
    } else if (position.getY() == lastPosition.getY() and position.getX() < lastPosition.getX()){
        mvwprintw(window, position.getY(), position.getX()*2 + 1, renderName.c_str());
    } else if (position.getY() == lastPosition.getY() and position.getX() > lastPosition.getX()){
        mvwprintw(window, position.getY(), position.getX()*2 - 1, renderName.c_str());
    }
    return *this;
}

void Entity::teleportCheck(Position & position){
    if (position.getX() < 0){
        position = Position(map->getWidth() - 1, position.getY());
    }
    if (position.getX() > map->getWidth() - 1){
        position = Position(0, position.getY());
    }
    if (position.getY() < 0){
        position = Position(position.getX(), map->getHeight() - 1);
    }
    if (position.getY() > map->getHeight() - 1){
        position = Position(position.getX(), 0);
    }
}

void Entity::teleportCheck(){
    teleportCheck(this->position);
}

Entity Entity::tick(){
    this->lastPosition = this->position;
    return *this;
}

void Entity::respawn(){
    this->position = this->spawnPosition;
    this->angle = Angle(2);
}