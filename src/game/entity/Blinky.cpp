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

void Blinky::tick(int tick, Position playerPosition){
    if (this->state == CAGED)
        return;
    this->state = SCATTER;

    this->lastPosition = this->position;
    Position nextPosition = this->position;

    if (this->state == SCATTER){
        while (this->path.size() <= 0){
            this->path = this->ai.calculatePath(this->map, this->position, ai.randomPosition(map));
            reverse(this->path.begin(), this->path.end());
        }
        nextPosition.move(this->path.at(path.size() - 1), 1);
        this->path.pop_back();
    }
    /*
    auto path = ai.calculatePath(this->map, this->position, playerPosition);
    if (path.size() > 0){
        nextPosition.move(path[0], 1);
    }*/

    this->position = nextPosition;
    teleportCheck();
}