#include "Inky.hpp"

using namespace std;



Inky::Inky():Ghost(){
    this->name = "Inky";
    this->saveName = "B";
    this->renderName = "BB";
    this->color = 6;
    this->angle = Angle(2);
}
//Copy consturctor
Inky::~Inky(){

}

void Inky::calculatePath(){
    //Calculate path
    //TODO
}

void Inky::tick(int tick){
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