#include "Entity.hpp"

Entity::Entity(){
    this->position = Position(0, 0);
    this->lastPosition = this->position;
    this->angle = Angle(0);
    this->isAlive = true;
    this->map = NULL;
}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->lastPosition = this->position;
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

Position Entity::getPosition(){
    return this->position;
}
Entity Entity::setPosition(Position position){
    this->position = position;
    this->lastPosition = this->position;
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
    wattron(window, COLOR_PAIR(1));
    if (map->point(position)){
        mvwprintw(window, position.getY(), position.getX()*2, "<>");
    } else {
        mvwprintw(window, position.getY(), position.getX()*2, "  ");    
    }
    if (map->point(lastPosition)){
        mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, "<>");
    } else {
        mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, "  ");    
    }
    return *this;
}

Entity Entity::render(WINDOW *window){
    wattron(window, COLOR_PAIR(color));
    mvwprintw(window, position.getY(), position.getX()*2, "██");
    return *this;
}

Entity Entity::renderHalf(WINDOW *window){
    if (position == lastPosition){
        render(window);
        return *this;
    }
    wattron(window, COLOR_PAIR(color));
    if (position.getX() == lastPosition.getX() and position.getY() < lastPosition.getY()){
        mvwprintw(window, position.getY(), position.getX()*2, "▄▄");
        mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, "▀▀");
    } else if (position.getX() == lastPosition.getX() and position.getY() > lastPosition.getY()){
        mvwprintw(window, position.getY(), position.getX()*2, "▀▀");
        mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, "▄▄");
    } else if (position.getY() == lastPosition.getY() and position.getX() < lastPosition.getX()){
        mvwprintw(window, position.getY(), position.getX()*2 + 1, "██");
    } else if (position.getY() == lastPosition.getY() and position.getX() > lastPosition.getX()){
        mvwprintw(window, position.getY(), position.getX()*2 - 1, "██");
    }
    return *this;
}

void Entity::teleportCheck(){
    if (this->position.getX() < 0){
        this->position = Position(map->getWidth() - 1, this->position.getY());
    }
    if (this->position.getX() > map->getWidth() - 1){
        this->position = Position(0, this->position.getY());
    }
    if (this->position.getY() < 0){
        this->position = Position(this->position.getX(), map->getHeight() - 1);
    }
    if (this->position.getY() > map->getHeight() - 1){
        this->position = Position(this->position.getX(), 0);
    }
}

Entity Entity::tick(){
    this->lastPosition = this->position;
    return *this;
}
