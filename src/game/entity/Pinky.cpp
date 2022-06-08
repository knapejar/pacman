#include "Pinky.hpp"

using namespace std;



Pinky::Pinky():Ghost(){
    this->name = "Pinky";
    this->color = 5;
    this->angle = Angle(2);
}
//Copy consturctor
Pinky::~Pinky(){

}

void Pinky::tick(int tick, Position playerPosition){
    if (this->state == CAGED)
        return;

    this->state = CHASE;

    this->lastPosition = this->position;
    Position nextPosition = this->position;
    
    if (this->state == CHASE){
        auto path = ai.calculatePath(this->map, this->position, playerPosition);
        if (path.size() > 0){
            nextPosition.move(path[0], 1);
        }
    }
    this->position = nextPosition;
    teleportCheck();
}