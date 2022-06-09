#include "Clyde.hpp"

using namespace std;



Clyde::Clyde():Ghost(){
    this->name = "Clyde";
    this->color = 4;
    this->angle = Angle(2);
}
//Copy consturctor
Clyde::~Clyde(){

}

void Clyde::tick(const int & tick, const Position & playerPosition){
    if (this->state == CAGED)
        return;
    if (this->state == FRIGHTENED){
        frightenedBehaviour(tick, playerPosition);
        return;
    }

    this->lastPosition = this->position;
    Position nextPosition = this->position;


    if (this->state == SCATTER){
        while (this->path.size() <= 0){
            this->path = this->ai.calculatePath(this->map, this->position, ai.randomPosition(map));
            reverse(this->path.begin(), this->path.end());
        }
        nextPosition.move(this->path.at(path.size() - 1), 1);
        this->path.pop_back();
    } else if (this->state == CHASE){    
        this->path = ai.calculatePath(this->map, this->position, playerPosition);
        if (this->path.size() < 5 && rand()%10 > 6){
            this->state = RANDOM;
            this->path.clear();
        } else if (this->path.size() > 0){
            nextPosition.move(this->path[0], 1);
        }
    } else {
        if (rand() % 10 > 8){
            this->state = CHASE;
        }

        if (rand() % 10 + 1 > 6)
            this->angle += Angle(1);
        for (int i = 0; i < 4; i++){
            nextPosition = this->position;
            nextPosition.move(this->angle, 1);
            teleportCheck(nextPosition);
            //Collision
            if (!map->wall(nextPosition)){
                break;
            }
            this->angle += Angle(3);
        }
    }



    this->position = nextPosition;
    teleportCheck();
}