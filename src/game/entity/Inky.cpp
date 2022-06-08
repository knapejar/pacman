#include "Inky.hpp"

using namespace std;



Inky::Inky():Ghost(){
    this->name = "Inky";
    this->color = 6;
    this->angle = Angle(2);
}
//Copy consturctor
Inky::~Inky(){

}

void Inky::tick(int tick, Position playerPosition){
    if (this->state == CAGED)
        return;

    this->lastPosition = this->position;
    Position nextPosition = this->position;
    if (rand() % 20 + 1 > 8)
        this->angle += Angle(3);
    for (int i = 0; i < 4; i++){
        nextPosition = this->position;
        nextPosition.move(this->angle, 1);
        teleportCheck(nextPosition);
        
        if (!map->wall(nextPosition)){
            break;
        }
        this->angle += Angle(1);
    }
    this->position = nextPosition;
    teleportCheck();
}