#include "Blinky.hpp"

using namespace std;



Blinky::Blinky():Ghost(){
    this->name = "Blinky";
    this->color = 3;
    this->angle = Angle(2);
}
//Copy consturctor
Blinky::~Blinky(){

}

void Blinky::calculatePath(){
    //Calculate path
    //TODO
}

void Blinky::tick(int tick, Position playerPosition){
    if (this->state == CAGED)
        return;

    this->lastPosition = this->position;
    Position nextPosition = this->position;

    auto path = ai.calculatePath(this->map, this->position, playerPosition);

    if (path.size() > 0){
        nextPosition.move(path[0], 1);
    }

    this->position = nextPosition;
    teleportCheck();
}