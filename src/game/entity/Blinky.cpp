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

void Blinky::tick(int tick){
    if (this->state == CAGED)
        return;

    this->lastPosition = this->position;
    Position nextPosition = this->position;

    int direction = rand() % 2;
    
    if (direction == 0){
        direction = -1;
    }

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
        this->angle += Angle(direction);
    }
    this->position = nextPosition;
    teleportCheck();
}