#include "Clyde.hpp"

Clyde::Clyde():Ghost(){
    this->name = "Clyde";
    this->saveName = "B";
    this->renderName = "BB";
    this->color = 4;
    this->angle = Angle(2);
}
//Copy consturctor
Clyde::~Clyde(){

}

void Clyde::calculatePath(){
    //Calculate path
    //TODO
}

void Clyde::tick(int tick){
    if (this->state == CAGED)
        return;

    this->lastPosition = this->position;
    Position nextPosition = this->position;
    if (rand() % 10 + 1 > 5)
        this->angle += Angle(3);
    for (int i = 0; i < 4; i++){
        nextPosition = this->position;
        nextPosition.move(this->angle, 1);
        teleportCheck(nextPosition);
        //Collision
        if (!map->wall(nextPosition)){
            break;
        }
        this->angle += Angle(1);
    }
    this->position = nextPosition;
    teleportCheck();
}