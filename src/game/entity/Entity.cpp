#include "Entity.hpp"

Entity::Entity(){
    this->position = Position(0, 0);
    this->angle = Angle(0);
    this->isAlive = true;
    this->name = "Entity";
    this->saveName = "?";
    this->renderName = "<>";
    this->color = COLOR_WHITE;
    this->map = NULL;
}

Entity::Entity(Position position, Angle angle){
    this->position = position;
    this->angle = angle;
    this->isAlive = true;
    this->name = "Entity";
    this->saveName = "?";
    this->renderName = "<>";
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
    Position nextPosition = this->position;
    nextPosition.move(this->angle, 1);
    if (!map->wall(nextPosition)){
        this->position = nextPosition;
    }
    return *this;
}

Entity Entity::hide(WINDOW *window){
    mvwprintw(window, position.getY(), position.getX()*2, "  ");
    return *this;
}

Entity Entity::render(WINDOW *window){
    init_pair(1, this->color, COLOR_BLACK);
    wattron(window, COLOR_PAIR(1));
    mvwprintw(window, position.getY(), position.getX()*2, "██");
    return *this;
}