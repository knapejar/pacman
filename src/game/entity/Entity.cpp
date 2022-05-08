#include "Entity.hpp"

Entity::Entity(){
    this->position = Position(0, 0);
    this->lastPosition = this->position;
    this->angle = Angle(0);
    this->isAlive = true;
    this->color = COLOR_WHITE;
    this->map = NULL;
}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->lastPosition = this->position;
    this->angle = angle;
    this->isAlive = true;
    this->color = COLOR_WHITE;
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
    mvwprintw(window, position.getY(), position.getX()*2, "  ");
    mvwprintw(window, lastPosition.getY(), lastPosition.getX()*2, "  ");
    return *this;
}

Entity Entity::render(WINDOW *window){
    init_pair(1, this->color, COLOR_BLACK);
    wattron(window, COLOR_PAIR(1));
    mvwprintw(window, position.getY(), position.getX()*2, "██");
    return *this;
}

Entity Entity::renderHalf(WINDOW *window){
    if (position == lastPosition){
        render(window);
        return *this;
    }
    init_pair(1, this->color, COLOR_BLACK);
    wattron(window, COLOR_PAIR(1));
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

Entity Entity::tick(){
    this->lastPosition = this->position;
    return *this;
}